package esj.codegen;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.lang.StringBuilder;

import org.eclipse.jdt.core.dom.ASTNode;
import org.eclipse.jdt.core.dom.ASTVisitor;
import org.eclipse.jdt.core.dom.ArrayAccess;
import org.eclipse.jdt.core.dom.ArrayCreation;
import org.eclipse.jdt.core.dom.Assignment;
import org.eclipse.jdt.core.dom.Block;
import org.eclipse.jdt.core.dom.BooleanLiteral;
import org.eclipse.jdt.core.dom.ClassInstanceCreation;
import org.eclipse.jdt.core.dom.CompilationUnit;
import org.eclipse.jdt.core.dom.ConditionalExpression;
import org.eclipse.jdt.core.dom.DoStatement;
import org.eclipse.jdt.core.dom.Expression;
import org.eclipse.jdt.core.dom.ExpressionStatement;
import org.eclipse.jdt.core.dom.FieldAccess;
import org.eclipse.jdt.core.dom.FieldDeclaration;
import org.eclipse.jdt.core.dom.ForStatement;
import org.eclipse.jdt.core.dom.IfStatement;
import org.eclipse.jdt.core.dom.InfixExpression;
import org.eclipse.jdt.core.dom.MethodDeclaration;
import org.eclipse.jdt.core.dom.MethodInvocation;
import org.eclipse.jdt.core.dom.Modifier;
import org.eclipse.jdt.core.dom.TypeDeclaration;
import org.eclipse.jdt.core.dom.VariableDeclarationFragment;
import org.eclipse.jdt.core.dom.VariableDeclarationStatement;
import org.eclipse.jdt.core.dom.WhileStatement;
import org.eclipse.jdt.internal.compiler.ast.IntLiteral;
import org.eclipse.jdt.core.dom.Modifier.ModifierKeyword;
import org.eclipse.jdt.core.dom.NullLiteral;
import org.eclipse.jdt.core.dom.NumberLiteral;
import org.eclipse.jdt.core.dom.ParenthesizedExpression;
import org.eclipse.jdt.core.dom.PostfixExpression;
import org.eclipse.jdt.core.dom.PrefixExpression;
import org.eclipse.jdt.core.dom.ReturnStatement;
import org.eclipse.jdt.core.dom.SimpleName;
import org.eclipse.jdt.core.dom.SingleVariableDeclaration;

import sjc.annotation.NonNull;
import sjc.annotation.NonNullElements;
import sjc.annotation.ReadOnlyElements;
import sjc.codegen.ByteCodeGenerator;
import sjc.symboltable.SymbolTable;
import sjc.symboltable.extended.ExtendedSymbolTable;
import sjc.test.Util;
import sjc.type.ArrayType;
import sjc.type.BooleanType;
import sjc.type.ClassType;
import sjc.type.IntType;
import sjc.type.NullType;
import sjc.type.Type;
import sjc.type.VoidType;
import sjc.type.checker.TypeTable;
import sjc.type.checker.extended.ExtendedTypeTable;
import sjc.util.Pair;
import org.stringtemplate.v4.*;

import esj.test.CcodegeneratorTest; 

public class Ccodegenerator {

	protected static class Visitor extends ASTVisitor{
		
		protected STGroup cTemplates = null;
		protected StringBuilder sb = null;
		
		protected StringBuilder structs = new StringBuilder();
		
		protected StringBuilder globalVars = new StringBuilder();
		
		protected StringBuilder methodDecls = new StringBuilder();
		
		protected StringBuilder methodDefs = new StringBuilder();
		
		protected StringBuilder typedefDecls = new StringBuilder();
		
		protected LinkedHashSet<Pair<String, String>> sanityChecks = new LinkedHashSet<Pair<String, String>>(); 
		
		protected HashMap<String, String> arrsizeMap = new HashMap<String,String>();
		
		protected ArrayList<String> localPtrs = new ArrayList<String>();
		
		protected String parentPtr = null;
		
		protected String arrSize = null;
		
		protected @NonNullElements @ReadOnlyElements Map<ASTNode, Object> symbolMap;

	    protected @NonNullElements @ReadOnlyElements Map<ASTNode, Type> typeMap;

	    protected @NonNullElements @ReadOnlyElements Map<Object, Pair<Type, List<Type>>> methodTypeMap;
	    
	    protected Visitor(@NonNull final SymbolTable st, @NonNull final TypeTable tt) {
	        assert (st != null) && (tt != null);
	        this.symbolMap = st.symbolMap;
	        this.typeMap = tt.typeMap;
	        this.methodTypeMap = tt.methodTypeMap;
	        try {
				final String filePath = Cutil.getResource(
						  CcodegeneratorTest.class,
				      "../..",
				      "Ctemplates.stg");
				this.cTemplates = new STGroupFile(filePath);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	        
	      }
	    
	    protected void dispose()
	    {
	    		this.cTemplates = null;
	    		this.globalVars = null;
	    		this.methodDecls = null;
	    		this.methodDefs = null;
	    		this.methodTypeMap = null;
	    		this.sb = null;
	    		this.structs = null;
	    		this.symbolMap = null;
	    		this.typeMap = null;
	    		
	    }
	    
	    /**
	     * Determines whether a {@link List} of {@link Modifier}s has a public
	     * modifier (a {@link Modifier}'s whose {@link ModifierKeyword} is
	     * {@link ModifierKeyword.PUBLIC_KEYWORD}).
	     * 
	     * @param modifiers
	     * @return True, if the {@link List} contains a public modifier.
	     */
	    protected boolean hasPublicModifier(
	        @SuppressWarnings("rawtypes") final List modifiers) {
	      for (final Object o : modifiers) {
	        if ((o instanceof Modifier)
	            && (((Modifier) o).getKeyword() == ModifierKeyword.PUBLIC_KEYWORD)) {
	          return true;
	        }
	      }
	      return false;
	    }
	    
	    protected String convertType(final Type t) {
	        if (t instanceof VoidType) {
	          return "void";
	        } else if (t instanceof BooleanType) {
	          return "bool";
	        } else if (t instanceof IntType) {
	          return "int";
	        } else if (t instanceof ClassType) {
	          return ((ClassType) t).name.replace('.', '/')+"*";
	        } else {
	          return (convertType(((ArrayType) t).baseType))+"*";
	        }
	      }
	    
	    protected void generateLocalVars(final VariableDeclarationStatement node)
	    {
	    		ST var = this.cTemplates.getInstanceOf("FieldDecl");
	    		VariableDeclarationFragment vdf = (VariableDeclarationFragment)node.fragments().get(0);
	    		String name = vdf.getName().getIdentifier();
	    		String type = convertType(this.typeMap.get(node));
	    		if(type.contains("*"))
	    		{
	    			this.localPtrs.add(name);
	    		}
	    		var.add("type", type);
	    		var.add("name", name);
	    		this.sb.append(var.render());
	    }
	    
	    
	    @Override
	    public boolean visit(final SimpleName node)
	    {
	    		this.sb.append(node.getIdentifier());
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final NumberLiteral node)
	    {
	    		this.sb.append(node.getToken());
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final BooleanLiteral node)
	    {
	    		if(node.booleanValue()){
	    			this.sb.append("true");
	    		}
	    		else{
	    			this.sb.append("false");
	    		}
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final NullLiteral node)
	    {
	    		this.sb.append("NULL");
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final ParenthesizedExpression node)
	    {
	    		StringBuilder sbtmp = this.sb;
	    		ST parenExp = this.cTemplates.getInstanceOf("parenExp");
	    		this.sb = new StringBuilder();
	    		node.getExpression().accept(this);
	    		parenExp.add("exp", this.sb.toString());
	    		sbtmp.append(parenExp.render());
	    		this.sb = sbtmp;
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final PrefixExpression node)
	    {
	    		StringBuilder sbtmp = this.sb;
			this.sb = new StringBuilder();
			ST prefixExp = this.cTemplates.getInstanceOf("unaryExp");
			node.getOperand().accept(this);
			prefixExp.add("exp", this.sb.toString());
			final PrefixExpression.Operator op = node.getOperator();
			if(op == PrefixExpression.Operator.MINUS)
			{
				prefixExp.add("op", "-");
			}
			else if(op == PrefixExpression.Operator.COMPLEMENT)
			{
				prefixExp.add("op", "~");
			}
			else if (op == PrefixExpression.Operator.NOT)
			{
				prefixExp.add("op", "!");
			}
			sbtmp.append(prefixExp.render());
			this.sb = sbtmp;
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final ConditionalExpression node)
	    {
	    		StringBuilder sbtmp = this.sb;
	    		ST condExp = this.cTemplates.getInstanceOf("condExp");
	    		this.sb = new StringBuilder();
	    		node.getExpression().accept(this);
	    		condExp.add("cond", this.sb.toString());
	    		this.sb = new StringBuilder();
	    		node.getThenExpression().accept(this);
	    		condExp.add("ifExp", this.sb.toString());
	    		this.sb = new StringBuilder();
	    		node.getElseExpression().accept(this);
	    		condExp.add("elseExp", this.sb.toString());
	    		sbtmp.append(condExp.render());
	    		this.sb = sbtmp;
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final ClassInstanceCreation node)
	    {
	    		Type t = this.typeMap.get(node);
	    		ST newExp = this.cTemplates.getInstanceOf("newStruct");
	    		newExp.add("name", t.name);
	    		if(this.parentPtr!=null)
	    			newExp.add("ptr", this.parentPtr);
	    		else
	    			newExp.add("ptr", "\"NULL\"");
	    		this.sb.append(newExp.render());
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final ArrayCreation node)
	    {
	    		final Type t = this.typeMap.get(node);
	    		StringBuilder sbtmp = this.sb;
	    		String type = convertType(t);
	    		if(type.contains("**"))
	    			type = type.replace("**", "*");
	    		else if(type.contains("*"))
	    			type = type.replace("*", "");
	    		if(node.dimensions()!=null && !node.dimensions().isEmpty())
	    		{
	    			this.sb = new StringBuilder();
	    			Expression e= (Expression)node.dimensions().get(0);
	    			e.accept(this);
	    			final ST newArray = this.cTemplates.getInstanceOf("newArray");
	    			newArray.add("type", type);
	    			newArray.add("nElems", this.sb.toString());
	    			if(this.parentPtr!=null)
	    				newArray.add("ptr", this.parentPtr);
		    		else
		    			newArray.add("ptr", "\"NULL\"");
	    			this.arrSize = this.sb.toString();
	    			sbtmp.append(newArray.render());
	    		}
	    		else if(node.getInitializer()!=null && !node.getInitializer().expressions().isEmpty())
	    		{
	    			final ST newArray = this.cTemplates.getInstanceOf("newArray");
	    			newArray.add("type", type);
	    			newArray.add("nElems", node.getInitializer().expressions().size());
	    			if(this.parentPtr!=null)
	    				newArray.add("ptr", this.parentPtr);
		    		else
		    			newArray.add("ptr", "\"NULL\"");
	    			this.arrSize = Integer.toString(node.getInitializer().expressions().size());
	    			sbtmp.append(newArray.render());
	    		}
	    		this.sb = sbtmp;
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final ArrayAccess node)
	    {
	    		StringBuilder sbtmp = this.sb;
	    		StringBuilder checkExp = new StringBuilder();
	    		ST arrExp = this.cTemplates.getInstanceOf("arrayAccessExp");
	    		this.sb = new StringBuilder();
	    		node.getArray().accept(this);
	    		arrExp.add("array",this.sb.toString());
	    		String arrName = this.sb.toString();
	    		if(this.parentPtr==null)
	    			this.parentPtr = arrName;
	    		String size = this.arrsizeMap.get(arrName);
	    		checkExp.append(arrName + "!=NULL");
	    		this.sb = new StringBuilder();
	    		node.getIndex().accept(this);
	    		if(size!=null)
	    		{
	    			checkExp.append(" && " + this.sb.toString() + 
		    				" < " + size);
	    		}
	    		
	    		String elseBlock = "printf(\"Error:Index Out Of Bounds near line %d\\n\",__LINE__);" 
	    				+ "\n" + "exit(-1);";
	    		arrExp.add("index",this.sb.toString());
	    		sbtmp.append(arrExp.render());
	    		this.sb = sbtmp;
	    		if(this.sanityChecks!=null)
	    		{
	    			Pair<String,String> p =  new Pair<String,String>(checkExp.toString(),
		    				elseBlock);
	    			this.sanityChecks.add(p);
	    		}
	    		
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final FieldAccess node)
	    {
	    		StringBuilder sbtmp = this.sb;
	    		ST fieldAccessExp = this.cTemplates.getInstanceOf("fieldAccessExp");
	    		fieldAccessExp.add("field",node.getName().getIdentifier());
	    		this.sb = new StringBuilder();
	    		node.getExpression().accept(this);
	    		fieldAccessExp.add("structName",this.sb.toString());
	    		String fieldName = this.sb.toString();
	    		if(this.parentPtr==null)
	    			this.parentPtr = fieldName;
	    		String checkExp = fieldName + " != NULL";
	    		String elseBlock = "printf(\"Error:Null Pointer reference near line %d\\n\",__LINE__);" 
	    				+ "\n" + "exit(-1);";
	    		sbtmp.append(fieldAccessExp.render());
	    		this.sb = sbtmp;
	    		if(this.sanityChecks!=null)
	    		{
	    			Pair<String,String> p =  new Pair<String,String>(checkExp,elseBlock);
	    			this.sanityChecks.add(p);
	    		}
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final InfixExpression node)
	    {
	    		StringBuilder sbtmp = this.sb;
	    		final ST infixExp = this.cTemplates.getInstanceOf("binExp");
	    		final InfixExpression.Operator op = node.getOperator();
	    		this.sb = new StringBuilder();
	    		node.getLeftOperand().accept(this);
	    		String exp1 = this.sb.toString();
	    		
	    		if (op == InfixExpression.Operator.PLUS) {
	    				infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.MINUS) {
	    	        		infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.TIMES) {
	    	        		infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.DIVIDE) {
	    	        		infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.REMAINDER) {
	    	        		infixExp.add("op", op);
	    	        }
	    	        else if (op == InfixExpression.Operator.LEFT_SHIFT) {
	    	        		infixExp.add("op", op);
	    	        }
	    	        else if(op == InfixExpression.Operator.RIGHT_SHIFT_SIGNED)
	    	        {
	    	        		infixExp.add("op", op);
	    	        }
	    	        else if(op == InfixExpression.Operator.RIGHT_SHIFT_UNSIGNED)
	    	        {
	    	        		exp1 = "((unsigned int)" + exp1 + ")";
	    	        		infixExp.add("op", ">>");
	    	        }
	    	        else if (op == InfixExpression.Operator.GREATER) {
	    	        		infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.GREATER_EQUALS) {
	    	        		infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.EQUALS) {
	    	        		infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.NOT_EQUALS) {
	    	        		infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.LESS) {
	    	        		infixExp.add("op", op);
	    	        } else if (op == InfixExpression.Operator.LESS_EQUALS) {
	    	        		infixExp.add("op", op);
	    	        }
	    	        else if(op == InfixExpression.Operator.CONDITIONAL_AND)
	    	        {
	    	        		infixExp.add("op", op);
	    	        }
	    	        else if(op == InfixExpression.Operator.CONDITIONAL_OR)
	    	        {
	    	        		infixExp.add("op", op);
	    	        }
	    		
	    		this.sb = new StringBuilder();
	    		node.getRightOperand().accept(this);
	    		infixExp.add("exp1", exp1);
	    		String exp2 = this.sb.toString();
	    		infixExp.add("exp2", exp2);
	    		sbtmp.append(infixExp.render());
	    		this.sb = sbtmp;
	    		if (op == InfixExpression.Operator.DIVIDE)
	    		{
	    			String checkExp = exp2 + "!=0";
	    			String elseBlock = "printf(\"Error:Divide by zero near line %d\\n\",__LINE__);" 
		    				+ "\n" + "exit(-1);";
	    			if(this.sanityChecks!=null)
		    		{
		    			Pair<String,String> p =  new Pair<String,String>(checkExp,elseBlock);
		    			this.sanityChecks.add(p);
		    		}
	    		}
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final Assignment node)
	    {
	    		ST assign = this.cTemplates.getInstanceOf("assignStmt");
	    		StringBuilder sbtmp = this.sb;
	    		this.sb = new StringBuilder();
	    		node.getLeftHandSide().accept(this);
	    		String lhs = this.sb.toString();
	    		if(this.parentPtr==null)
	    			this.parentPtr = lhs;
	    		assign.add("lhs", this.sb.toString());
	    		this.sb = new StringBuilder();
	    		node.getRightHandSide().accept(this);
	    		assign.add("rhs", this.sb.toString());
	    		sbtmp.append(assign.render());
	    		if(node.getRightHandSide() instanceof ArrayCreation)
	    		{
	    			if(this.arrSize!=null)
		    			this.arrsizeMap.put(lhs, this.arrSize);
	    			this.arrSize = null;
	    			ArrayCreation exp = (ArrayCreation) node.getRightHandSide();
	    			if(exp.getInitializer()!=null && !exp.getInitializer().expressions().isEmpty())
	    			{
	    				int i=0;
	    				for(Object o: exp.getInitializer().expressions())
	    				{
	    					this.sb = new StringBuilder();
	    					((ASTNode)o).accept(this);
	    					ST initArrExp = this.cTemplates.getInstanceOf("initArray");
	    					initArrExp.add("name", lhs);
	    					initArrExp.add("index", i);
	    					initArrExp.add("val",this.sb.toString());
	    					sbtmp.append(initArrExp.render());
	    					i++;
	    				}
	    			}
	    		}
	    		this.sb = sbtmp;
	    		this.parentPtr = null;
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final IfStatement node)
	    {
	    		StringBuilder sbtmp = this.sb;
	    		if(node.getElseStatement()!=null)
	    		{
	    			ST ifelse = this.cTemplates.getInstanceOf("ifelseStmt");
	    			this.sb = new StringBuilder();
	    			node.getExpression().accept(this);
	    			ifelse.add("cond", this.sb.toString());
	    			this.sb = new StringBuilder();
	    			node.getThenStatement().accept(this);
	    			ifelse.add("thenBlock", this.sb.toString());
	    			this.sb = new StringBuilder();
	    			node.getElseStatement().accept(this);
	    			ifelse.add("elseBlock", this.sb.toString());
	    			sbtmp.append(ifelse.render());
	    			this.sb = sbtmp;
	    		}
	    		else
	    		{
	    			ST iftemplate = this.cTemplates.getInstanceOf("ifStmt");
	    			this.sb = new StringBuilder();
	    			node.getExpression().accept(this);
	    			iftemplate.add("cond", this.sb.toString());
	    			this.sb = new StringBuilder();
	    			node.getThenStatement().accept(this);
	    			iftemplate.add("block", this.sb.toString());
	    			sbtmp.append(iftemplate.render());
	    			this.sb = sbtmp;
	    		}
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final WhileStatement node)
	    {
	    		StringBuilder sbtmp = this.sb;
	    		ST whiletemplate = this.cTemplates.getInstanceOf("whileStmt");
	    		this.sb = new StringBuilder();
	    		node.getExpression().accept(this);
	    		whiletemplate.add("cond", this.sb.toString());
	    		this.sb = new StringBuilder();
	    		node.getBody().accept(this);
		    	whiletemplate.add("block", this.sb.toString());
	    		sbtmp.append(whiletemplate.render());
	    		this.sb = sbtmp;
	    		return false;
	    }
	
	    @Override
	    public boolean visit(final ReturnStatement node)
	    {
	    		if(node.getExpression()!=null)
	    		{
	    			Type t = this.typeMap.get(node.getExpression());
	    			StringBuilder sbtmp = this.sb;
	    			this.sb = new StringBuilder();
	    			StringBuilder nullStmts = null;
	    			if(this.localPtrs!=null && !(this.localPtrs.isEmpty()))
	    			{
	    				nullStmts = new StringBuilder();
	    				for(int i=0;i<this.localPtrs.size();i++)
	    				{
	    					String stmt = this.localPtrs.get(i) + "= NULL;\n";
	    					nullStmts.append(stmt);
	    				}
	    			}
	    			if(!(t instanceof NullType))
	    			{
	    				String type = convertType(t);	
			    		ST returnExp = this.cTemplates.getInstanceOf("returnStmt");
			    		node.getExpression().accept(this);
			    		returnExp.add("exp",this.sb.toString());
			    		returnExp.add("type", type);
			    		returnExp.add("nullStmts", nullStmts);
			    		sbtmp.append(returnExp.render());
	    			}
	    			else
	    			{
			    		ST returnExp = this.cTemplates.getInstanceOf("returnNull");
			    		returnExp.add("nullStmts", nullStmts);
			    		sbtmp.append(returnExp.render());
	    			}
		    		this.sb = sbtmp;
	    		}
	    		
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final ForStatement node)
	    {
	    		StringBuilder tmpsb = this.sb;
	    		ST forStmt = this.cTemplates.getInstanceOf("forStmt");
	    		this.sb = new StringBuilder();
	    		for(Object o:node.initializers())
	    		{
	    			((ASTNode)o).accept(this);
	    			//this.sb.append(",");
	    		}
	    		String inits = this.sb.toString().replace(";\n", ",");
	    		if(inits.length()>0)
	    			inits = inits.substring(0,inits.length()-1);
	    		forStmt.add("init",inits);
	    		this.sb = new StringBuilder();
	    		if(node.getExpression()!=null)
	    			node.getExpression().accept(this);
	    		forStmt.add("term", this.sb.toString());
	    		this.sb = new StringBuilder();
	    		for(Object o:node.updaters())
	    		{
	    			((ASTNode)o).accept(this);
	    			this.sb.append(",");
	    		}
	    		String upds = this.sb.toString().replace(";\n", "");
	    		if(upds.length()>0)
	    			upds = upds.substring(0,upds.length()-1);
	    		forStmt.add("upd",upds);
	    		this.sb = new StringBuilder();
	    		node.getBody().accept(this);
	    		forStmt.add("block", this.sb.toString());
	    		tmpsb.append(forStmt.render());
	    		this.sb = tmpsb;
	    		
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final DoStatement node)
	    {
	    		ST doWhileExp = this.cTemplates.getInstanceOf("dowhileStmt");
	    		StringBuilder sbtmp = this.sb;
	    		this.sb = new StringBuilder();
	    		node.getExpression().accept(this);
	    		doWhileExp.add("cond", this.sb.toString());
	    		this.sb = new StringBuilder();
	    		node.getBody().accept(this);
	    		doWhileExp.add("block", this.sb.toString());
	    		sbtmp.append(doWhileExp.render());
	    		this.sb = sbtmp;
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final PostfixExpression node)
	    {
	    		StringBuilder sbtmp = this.sb;
			this.sb = new StringBuilder();
			ST postfixExp = this.cTemplates.getInstanceOf("postExp");
			node.getOperand().accept(this);
			postfixExp.add("exp", this.sb.toString());
			final PostfixExpression.Operator op = node.getOperator();
			if(op == PostfixExpression.Operator.INCREMENT)
			{
				postfixExp.add("op", "++");
			}
			else if(op == PostfixExpression.Operator.DECREMENT)
			{
				postfixExp.add("op", "--");
			}
			sbtmp.append(postfixExp.render());
			this.sb = sbtmp;
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final ExpressionStatement node)
	    {
	    		
	    		if(node.getExpression() instanceof MethodInvocation)
	    		{
	    			StringBuilder sbtmp = this.sb;
	    			this.sb = new StringBuilder();
	    			MethodInvocation mi = (MethodInvocation)node.getExpression();
	    			String methodName = mi.getName().getIdentifier();
	    			ST invokeStmt = this.cTemplates.getInstanceOf("invokeStmt");
	    			
	    			for(Object o: mi.arguments())
	    			{
	    				((ASTNode)o).accept(this);
	    				this.sb.append(",");
	    			}
	    			String args = this.sb.toString();
	    			if(args.length()>0)
	    			{
	    				args = args.substring(0,args.length()-1);
	    			}
	    			else if(methodName.equalsIgnoreCase("println"))
	    			{
	    				methodName = methodName + "_v";
	    			}
	    			invokeStmt.add("name",methodName);
	    			invokeStmt.add("args", args);
	    			String stmt = invokeStmt.render();
	    			
	    			ArrayList<Pair<String,String>> errCheckConds = new ArrayList<Pair<String,String>>();
		    		for(Object o: this.sanityChecks)
		    		{
		    			errCheckConds.add((Pair<String, String>) o);
		    		}
	    			for(int i=errCheckConds.size()-1;i>=0;i--)
	    			{
	    				Pair<String,String> sc = (Pair<String, String>) errCheckConds.get(i);
	    				ST ifelseStmt = this.cTemplates.getInstanceOf("ifelseStmt");
	    				String ifExp = sc.first;
	    				String elseBlock = sc.second;
	    				ifelseStmt.add("cond", ifExp);
	    				ifelseStmt.add("elseBlock", elseBlock);
	    				ifelseStmt.add("thenBlock", stmt);
	    				stmt = ifelseStmt.render();
	    			}
	    			sbtmp.append(stmt);
	    			this.sb = sbtmp;
	    			this.sanityChecks = new LinkedHashSet<Pair<String,String>>();
	    			errCheckConds = null;
	    		}
	    		else if(node.getExpression() instanceof PostfixExpression)
	    		{
	    			StringBuilder sbtmp = this.sb;
	    			this.sb = new StringBuilder();
	    			PostfixExpression pfe = (PostfixExpression) node.getExpression();
	    			ST postfixStmt = this.cTemplates.getInstanceOf("incDecStmt");
	    			pfe.getOperand().accept(this);
	    			postfixStmt.add("exp", this.sb.toString());
	    			final PostfixExpression.Operator op = pfe.getOperator();
	    			if(op == PostfixExpression.Operator.INCREMENT)
	    			{
	    				postfixStmt.add("op", "++");
	    			}
	    			else if(op == PostfixExpression.Operator.DECREMENT)
	    			{
	    				postfixStmt.add("op", "--");
	    			}
	    			String stmt = postfixStmt.render();
	    			ArrayList<Pair<String,String>> errCheckConds = new ArrayList<Pair<String,String>>();
		    		for(Object o: this.sanityChecks)
		    		{
		    			errCheckConds.add((Pair<String, String>) o);
		    		}
	    			for(int i=errCheckConds.size()-1;i>=0;i--)
	    			{
	    				Pair<String,String> sc = (Pair<String, String>) errCheckConds.get(i);
	    				ST ifelseStmt = this.cTemplates.getInstanceOf("ifelseStmt");
	    				String ifExp = sc.first;
	    				String elseBlock = sc.second;
	    				ifelseStmt.add("cond", ifExp);
	    				ifelseStmt.add("elseBlock", elseBlock);
	    				ifelseStmt.add("thenBlock", stmt);
	    				stmt = ifelseStmt.render();
	    			}
	    			sbtmp.append(stmt);
	    			this.sb = sbtmp;
	    			this.sanityChecks = new LinkedHashSet<Pair<String,String>>();
	    			errCheckConds = null;
	    		}
	    		else
	    		{
	    			StringBuilder sbtmp;
	    			sbtmp = this.sb;
	    			this.sb = new StringBuilder();
	    			node.getExpression().accept(this);
	    			String stmt = this.sb.toString();
	    			ArrayList<Pair<String,String>> errCheckConds = new ArrayList<Pair<String,String>>();
		    		for(Object o: this.sanityChecks)
		    		{
		    			errCheckConds.add((Pair<String, String>) o);
		    		}
	    			for(int i=errCheckConds.size()-1;i>=0;i--)
	    			{
	    				Pair<String,String> sc = (Pair<String, String>) errCheckConds.get(i);
	    				ST ifelseStmt = this.cTemplates.getInstanceOf("ifelseStmt");
	    				String ifExp = sc.first;
	    				String elseBlock = sc.second;
	    				ifelseStmt.add("cond", ifExp);
	    				ifelseStmt.add("elseBlock", elseBlock);
	    				ifelseStmt.add("thenBlock", stmt);
	    				stmt = ifelseStmt.render();
	    			}
	    			sbtmp.append(stmt);
	    			this.sb = sbtmp;
	    			this.sanityChecks = new LinkedHashSet<Pair<String,String>>();
	    			errCheckConds = null;
	    		}
	    		
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final MethodInvocation node)
	    {
	    		StringBuilder sbtmp = this.sb;
			this.sb = new StringBuilder();
			ST invokeExp = this.cTemplates.getInstanceOf("invokeExp");
			String methodName = node.getName().getIdentifier();
			
			for(Object o: node.arguments())
			{
				((ASTNode)o).accept(this);
				this.sb.append(",");
			}
			String args = this.sb.toString();
			if(args.length()>0)
			{
				args = args.substring(0,args.length()-1);
			}
			else if(methodName.equalsIgnoreCase("println"))
			{
				methodName = methodName + "_v";
			}
			invokeExp.add("name",methodName);
			invokeExp.add("args", args);
			sbtmp.append(invokeExp.render());
			this.sb = sbtmp;
	    		return false;
	    }
	    
	    @Override 
	    public boolean visit(final VariableDeclarationStatement node)
	    {
	    		
	    		VariableDeclarationFragment vdf = (VariableDeclarationFragment)node.fragments().get(0);
	    		String name = vdf.getName().getIdentifier();
	    		String type = convertType(this.typeMap.get(node));
	    		if(vdf.getInitializer()!=null)
	    		{
	    			StringBuilder sbtmp = this.sb;
	    			ST var = this.cTemplates.getInstanceOf("FieldDeclInit");
		    		var.add("type", type);
		    		var.add("name", name);
		    		this.sb = new StringBuilder();
		    		vdf.getInitializer().accept(this);
		    		var.add("val", this.sb.toString());
		    		sbtmp.append(var.render());
		    		if(vdf.getInitializer() instanceof ArrayCreation)
		    		{
		    			ArrayCreation exp = (ArrayCreation)vdf.getInitializer();
		    			if(exp.getInitializer()!=null && !exp.getInitializer().expressions().isEmpty())
		    			{
		    				int i=0;
		    				for(Object o: exp.getInitializer().expressions())
		    				{
		    					this.sb = new StringBuilder();
		    					((ASTNode)o).accept(this);
		    					ST initArrExp = this.cTemplates.getInstanceOf("initArray");
		    					initArrExp.add("name", name);
		    					initArrExp.add("index", i);
		    					initArrExp.add("val",this.sb.toString());
		    					sbtmp.append(initArrExp.render());
		    					i++;
		    				}
		    			}
		    		}
		    		this.sb = sbtmp;
	    		}
	    		else
	    		{
	    			ST var = this.cTemplates.getInstanceOf("FieldDecl");
		    		var.add("type", type);
		    		var.add("name", name);
		    		this.sb.append(var.render());
	    		}
	    		
	    		
	    		return false;
	    }
	    
	    @Override 
	    public boolean visit(final FieldDeclaration node)
	    {
	    		ST fd = this.cTemplates.getInstanceOf("FieldDecl");
	    		VariableDeclarationFragment vdf = (VariableDeclarationFragment)node.fragments().get(0);
	    		String name = vdf.getName().getIdentifier();
	    		String type = convertType(this.typeMap.get(node));
	    		fd.add("type", type);
	    		fd.add("name", name);
	    		this.sb.append(fd.render());
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final MethodDeclaration node)
	    {
	    		
	    		final String methodName = node.getName().getIdentifier();
	        final Pair<Type, List<Type>> methodType = this.methodTypeMap.get(node);
	        String retType = convertType(methodType.first);
	        ArrayList<String> formalParms = null;
	        if(node.parameters()!=null)
	        {
	        		formalParms = new ArrayList<String>();
	        		for(Object o: node.parameters())
		        {
		        		SingleVariableDeclaration svd = (SingleVariableDeclaration) o;
		        		formalParms.add(convertType(this.typeMap.get(svd))
		        				+" "+svd.getName().getIdentifier());
		        }
	        }
	        
	        if(!methodName.equalsIgnoreCase("main"))
	        {
	        		ST mDecl = this.cTemplates.getInstanceOf("methodDecl");
	        		ArrayList<String> parms = new ArrayList<String>();
		        if(methodType.second!=null && !methodType.second.isEmpty())
		        {
		        		for(Type t: methodType.second)
		        		{
		        			parms.add(convertType(t));
		        		}
		        }
		        if(!parms.isEmpty())
		        {
		        		mDecl.add("name", methodName);
		        		mDecl.add("returnType", retType);
		        		mDecl.add("args", parms);
		        }
		        else
		        {
		        	mDecl.add("name", methodName);
	        		mDecl.add("returnType", retType);
	        		mDecl.add("args", null);
		        }
		        this.methodDecls.append(mDecl.render());
		        
		        this.sb = new StringBuilder();
		        for(Object o: node.getBody().statements())
		        {
		        		if(o instanceof VariableDeclarationStatement)
		        		{
		        			generateLocalVars((VariableDeclarationStatement)o);
		        		}
		        		else
		        		{
		        			((ASTNode)o).accept(this);
		        		}
		        		
		        }
		        ST mDef = this.cTemplates.getInstanceOf("methodDef");
		        mDef.add("name", methodName);
		        mDef.add("returnType", retType);
		        mDef.add("args", formalParms);
		        mDef.add("body", this.sb.toString());
		        this.methodDefs.append(mDef.render());
	        }
	        else
	        {
	        		this.sb = new StringBuilder();
		        for(Object o: node.getBody().statements())
		        {
		        		if(o instanceof VariableDeclarationStatement)
		        		{
		        			generateLocalVars((VariableDeclarationStatement)o);
		        		}
		        		else
		        		{
		        			((ASTNode)o).accept(this);
		        		}
		        		
		        }
		        ST mDef = this.cTemplates.getInstanceOf("mainMethod");
		        mDef.add("body", this.sb.toString());
		        StringBuilder nullStmts = null;
    				if(this.localPtrs!=null && !(this.localPtrs.isEmpty()))
    				{
    					nullStmts = new StringBuilder();
    					for(int i=0;i<this.localPtrs.size();i++)
    					{
    						String stmt = this.localPtrs.get(i) + "= NULL;\n";
    						nullStmts.append(stmt);
    					}
    				}
    				mDef.add("nullStmts", nullStmts);
		        this.methodDefs.append(mDef.render());
	        }
	        this.localPtrs = new ArrayList<String>();
	        this.sb = null;
	    		return false;
	    }
	    
	    @Override
	    public boolean visit(final TypeDeclaration node)
	    {
	    		String className = node.getName().getIdentifier();
	    		this.typedefDecls.append("typedef struct "+className+ " " + className + ";\n");
	    		if(!this.hasPublicModifier(node.modifiers())){
	    			ST struct = this.cTemplates.getInstanceOf("simpleClass");
	    			struct.add("name", className);
	    			this.sb = new StringBuilder();
	    			for(Object o: node.bodyDeclarations()){
	    				
	    				((ASTNode) o).accept(this);
	    			}
	    			struct.add("members", this.sb.toString());
	    			this.structs.append(struct.render());
	    			this.sb = null;
	    		}
	    		else
	    		{
	    			for(Object o:node.bodyDeclarations())
	    			{
	    				if(o instanceof FieldDeclaration)
	    				{
	    					ST var = this.cTemplates.getInstanceOf("FieldDecl");
	    					FieldDeclaration fd = (FieldDeclaration)o;
	    		    			VariableDeclarationFragment vdf = (VariableDeclarationFragment)fd.fragments().get(0);
	    		    			String name = vdf.getName().getIdentifier();
	    		    			String type = convertType(this.typeMap.get(o));
	    		    			var.add("type", type);
	    		    			var.add("name", name);
	    		    			this.globalVars.append(var.render());
	    				}
	    				else
	    				{
	    					((ASTNode)o).accept(this);
	    				}
	    				
	    			}
	    		}
	    		
	    		return false;
	    }
	}
	
	public static @NonNull
	CprogramCode generate(@NonNull final CompilationUnit cu,
	      @NonNull final ExtendedSymbolTable est,
	      @NonNull final ExtendedTypeTable ett) throws ByteCodeGenerator.Error {
	    assert (cu != null) && (est != null) && (ett != null);

	    final Visitor v = new Visitor(est, ett);
	    cu.accept(v);
	    final CprogramCode result = new CprogramCode(v.typedefDecls,
	        v.structs, v.globalVars, v.methodDecls,v.methodDefs);
	    v.dispose();
	    return result;
	  }
}
