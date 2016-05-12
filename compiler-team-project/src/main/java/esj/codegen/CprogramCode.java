package esj.codegen;

public class CprogramCode {

	public StringBuilder typedefs;
	
	public StringBuilder structs;
	
	public StringBuilder globalVars;
	
	public StringBuilder methodDecls;
	
	public StringBuilder methodDefs;
	
	protected CprogramCode(StringBuilder typedefs,StringBuilder structs, StringBuilder globalVars,
			StringBuilder methodDecls, StringBuilder methodDefs)
	{
		this.typedefs = typedefs;
		this.structs = structs;
		this.globalVars = globalVars;
		this.methodDecls = methodDecls;
		this.methodDefs = methodDefs;
	}
}
