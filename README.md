# TeamD
Compiler Extended Java to C Translator:
Team members: Joydeep Mitra and Wendy Tan 
Presentation : <relative path to the presented slides .pdf file>
——-PART A - Translation - 10 points 

Path to string template: /src/main/java/esj/codegen/Ctemplates.stg 

List of test cases added to check translation and exception handling:

          @Test
	  public void testAEEmptyTest() {
	    testPass("AEEmptyTest.java");
	  }

	  @Test
	  public void testArrayAccessVariable() {
	    testPass("ArrayAccessVariable.java");
	  }

	  @Test
	  public void testArrayCreation() {
	    testPass("ArrayCreation.java");
	  }

	  @Test
	  public void testArrayCreation2() {
	    testPass("ArrayCreation2.java");
	  }

	  @Test
	  public void testArrayIndex() {
	    testPass("ArrayIndex.java");
	  }

	  @Test
	  public void testArrayIndexConstant() {
	    testPass("ArrayIndexConstant.java");
	  }

	  @Test
	  public void testAssignNullToObject() {
	    testPass("AssignNullToObject.java");
	  }

	  @Test
	  public void testBasicTypes() {
	    testPass("BasicTypes.java");
	  }

	  @Test
	  public void testBinaryOps() {
	    testPass("BinaryOps.java");
	  }

	  @Test
	  public void testBooleanAnd() {
	    testPass("BooleanAnd.java");
	  }

	  @Test
	  public void testBooleanLiteral() {
	    testPass("BooleanLiteral.java");
	  }

	  @Test
	  public void testBooleanNot() {
	    testPass("BooleanNot.java");
	  }

	  @Test
	  public void testBooleanOr() {
	    testPass("BooleanOr.java");
	  }

	  @Test
	  public void testConditionalFalse() {
	    testPass("ConditionalFalse.java");
	  }

	  @Test
	  public void testConditionalTrue() {
	    testPass("ConditionalTrue.java");
	  }

	  @Test
	  public void testConditionalWithNull() {
	    testPass("ConditionalWithNull.java");
	  }

	  @Test
	  public void testCreateIntArrayWithIntAndIntLiteralInitializers() {
	    testPass("CreateIntArrayWithIntAndIntLiteralInitializers.java");
	  }

	  @Test
	  public void testDoWhile() {
	    testPass("DoWhile.java");
	  }

	  @Test
	  public void testDoWhileWithBooleanArrayAccessCondition() {
	    testPass("DoWhileWithBooleanArrayAccessCondition.java");
	  }

	  @Test
	  public void testFactorial() {
	    testPass("Factorial.java");
	  }

	  @Test
	  public void testFieldAccess() {
	    testPass("FieldAccess.java");
	  }

	 @Test
	  public void testFor() {
	    testPass("For.java");
	  }

	  @Test
	  public void testForBooleanArrayAccessConditional() {
	    testPass("ForBooleanArrayAccessConditional.java");
	  }

	  @Test
	  public void testForBooleanMemberAccessConditional() {
	    testPass("ForBooleanMemberAccessConditional.java");
	  }

	  @Test
	  public void testForCondOnly() {
	    testPass("ForCondOnly.java");
	  }

	  @Test
	  public void testForEmpty() {
	    testPass("ForEmpty.java");
	  }

	  @Test
	  public void testForFull() {
	    testPass("ForFull.java");
	  }

	  @Test
	  public void testForIncOrDecOnly() {
	    testPass("ForIncOrDecOnly.java");
	  }

	  @Test
	  public void testForInitOnly() {
	    testPass("ForInitOnly.java");
	  }

	  @Test
	  public void testForLoop() {
	    testPass("ForLoop.java");
	  }

	  @Test
	  public void testForMissingCond() {
	    testPass("ForMissingCond.java");
	  }

	  @Test
	  public void testForMissingIncOrDec() {
	    testPass("ForMissingIncOrDec.java");
	  }

	  @Test
	  public void testForMissingInit() {
	    testPass("ForMissingInit.java");
	  }

	  @Test
	  public void testForMultipleIncOrDecOnly() {
	    testPass("ForMultipleIncOrDecOnly.java");
	  }

	  @Test
	  public void testForMultipleInitAndIncOrDec() {
	    testPass("ForMultipleInitAndIncOrDec.java");
	  }

	  @Test
	  public void testForMultipleInitOnly() {
	    testPass("ForMultipleInitOnly.java");
	  }

	  @Test
	  public void testForwardClassTest() {
	    testPass("ForwardClassTest.java");
	  }

	  @Test
	  public void testIf() {
	    testPass("If.java");
	  }

	  @Test
	  public void testIfFalseEmpty() {
	    testPass("IfFalseEmpty.java");
	  }

	  @Test
	  public void testIfFalseSingle() {
	    testPass("IfFalseSingle.java");
	  }

	  @Test
	  public void testIfFalseSingleElseEmpty() {
	    testPass("IfFalseSingleElseEmpty.java");
	  }

	  @Test
	  public void testIfFalseSingleElseMultiple() {
	    testPass("IfFalseSingleElseMultiple.java");
	  }

	  @Test
	  public void testIfFalseSingleElseSingle() {
	    testPass("IfFalseSingleElseSingle.java");
	  }

	  @Test
	  public void testIfTrueEmpty() {
	    testPass("IfTrueEmpty.java");
	  }

	  @Test
	  public void testIfTrueEmptyElseEmpty() {
	    testPass("IfTrueEmptyElseEmpty.java");
	  }

	  @Test
	  public void testIfTrueMultiple() {
	    testPass("IfTrueMultiple.java");
	  }

	  @Test
	  public void testIfTrueSingle() {
	    testPass("IfTrueSingle.java");
	  }

	  @Test
	  public void testIfTrueSingleElseEmpty() {
	    testPass("IfTrueSingleElseEmpty.java");
	  }

	  @Test
	  public void testIfTrueSingleElseSingle() {
	    testPass("IfTrueSingleElseSingle.java");
	  }

	  @Test
	  public void testIncIntArrayAccess() {
	    testPass("IncIntArrayAccess.java");
	  }

	  @Test
	  public void testIntAdd() {
	    testPass("IntAdd.java");
	  }

	  @Test
	  public void testIntComplement() {
	    testPass("IntComplement.java");
	  }

	  @Test
	  public void testIntDivide() {
	    testPass("IntDivide.java");
	  }

	  @Test
	  public void testIntEqual() {
	    testPass("IntEqual.java");
	  }

	  @Test
	  public void testIntGreaterThan() {
	    testPass("IntGreaterThan.java");
	  }

	  @Test
	  public void testIntGreaterThanOrEqual() {
	    testPass("IntGreaterThanOrEqual.java");
	  }

	  @Test
	  public void testIntLessThan() {
	    testPass("IntLessThan.java");
	  }

	  @Test
	  public void testIntLessThanOrEqual() {
	    testPass("IntLessThanOrEqual.java");
	  }

	  @Test
	  public void testIntMultiply() {
	    testPass("IntMultiply.java");
	  }

	  @Test
	  public void testIntNegate() {
	    testPass("IntNegate.java");
	  }

	  @Test
	  public void testIntNotEqual() {
	    testPass("IntNotEqual.java");
	  }

	  @Test
	  public void testIntPlus() {
	    testPass("IntPlus.java");
	  }

	  @Test
	  public void testIntPostDecrement() {
	    testPass("IntPostDecrement.java");
	  }

	  @Test
	  public void testIntPostIncrement() {
	    testPass("IntPostIncrement.java");
	  }

	  @Test
	  public void testIntRemainder() {
	    testPass("IntRemainder.java");
	  }

	  @Test
	  public void testIntShiftLeft() {
	    testPass("IntShiftLeft.java");
	  }

	  @Test
	  public void testIntShiftRight() {
	    testPass("IntShiftRight.java");
	  }

	  @Test
	  public void testIntSubtract() {
	    testPass("IntSubtract.java");
	  }
	  
	  @Test
	  public void testIntUnsignedShiftRight() {
	    testPass("IntUnsignedShiftRight.java");
	  }

	  @Test
	  public void testNewBasic() {
	    testPass("NewBasic.java");
	  }

	  @Test
	  public void testNewID() {
	    testPass("NewID.java");
	  }

	  @Test
	  public void testNullArgumentForIntArrayParameter() {
	    testPass("NullArgumentForIntArrayParameter.java");
	  }

	  @Test
	  public void testNullEqualsNull() {
	    testPass("NullEqualsNull.java");
	  }

	  @Test
	  public void testObjectAEqualsReturnedObjectA() {
	    testPass("ObjectAEqualsReturnedObjectA.java");
	  }

	  @Test
	  public void testParens() {
	    testPass("Parens.java");
	  }

	  @Test
	  public void testPower() {
	    testPass("Power.java");
	  }

	  @Test
	  public void testQueue() {
	    testPass("Queue.java");
	  }
	  
	  @Test
	  public void testReturnNullFromIntArrayMethod() {
	    testPass("ReturnNullFromIntArrayMethod.java");
	  }

	  @Test
	  public void testSAExample() {
	    testPass("SAExample.java");
	  }

	  @Test
	  public void testSymbolTableTest() {
	    testPass("SymbolTableTest.java");
	  }

	  @Test
	  public void testSyntaxTorture() {
	    testPass("SyntaxTorture.java");
	  }

	  @Test
	  public void testTypesArray() {
	    testPass("TypesArray.java");
	  }

	  @Test
	  public void testTypesBasic() {
	    testPass("TypesBasic.java");
	  }

	  @Test
	  public void testTypesID() {
	    testPass("TypesID.java");
	  }

	  @Test
	  public void testUnaryOps() {
	    testPass("UnaryOps.java");
	  }
	  
	  @Test
	  public void testWhile() {
	    testPass("While.java");
	  }

Contribution:
Joydeep Mitra = 100%
Wendy Tan = 0%

———PART B - StaticJavaLib to C - 2.5 points

Path to the C lib file: /bin/esj/codegen/staticlib.h

Contribution:
Joydeep Mitra = 100%
Wendy Tan = 0%

———PART C - Garbage collector - 10 points

Path to the Garbage collector code: /bin/esj/codegen/my_alloc.h

List of test cases added to test garbage collector:

          @Test
	  public void testCreateArrayOfOneMillionObjects(){
		  testPass("CreateArrayOfOneMillionObjects.java");
	  }
	  
	  @Test
	  public void testOneMillionObjects(){
		  testPass("OneMillionObjects.java");
	  }
	  
	  @Test
	  public void testSumOneMillionIntegers(){
		  testPass("SumOneMillionIntegers.java");
	  }
	 
	  @Test
	  public void testSearchOneMillionInts(){
		  testPass("SearchOneMillionInts.java");
	  }
	  
	  @Test
	  public void testCopyOneMillionObjects(){
		  testPass("CopyOneMillionObjects.java");
	  }
	 
	  @Test 
	  public void testComplementArray(){
		  testPass("ComplementArray.java");
	  }

	  @Test 
	  public void testCopyArrayElemToField(){
		  testPass("CopyArrayElemToField.java");
	  }
	  
	  @Test
	  public void testDivisibleByFive(){
		  testPass("DivisibleByFive.java");
	  }
	  
	  @Test
	  public void testDoubleList(){
		  testPass("DoubleList.java");
	  }
	  
	  @Test
	  public void testBinSearch(){
		  testPass("BinSearch.java");
	  }
	  
	  @Test
	  public void testObjectEquality(){
		  testPass("ObjectEquality.java");
	  }
	  
	  @Test
	  public void testPostfixArray(){
		  testPass("PostfixArray.java");
	  }
	  
	  @Test
	  public void testFieldAccessArray(){
		  testPass("FieldAccessArray.java");
	  }
	  
	  @Test
	  public void testObjectSum(){
		  testPass("ObjectSum.java");
	  }

Contribution:
Joydeep Mitra = 100%
Wendy Tan = 0%

———PART D - Test infrastructure - 2.5 points

Path to the test harness file: /src/test/resources/
Path to the generated c files: /bin/esj/codegen/

Contribution:
Joydeep Mitra = 100%
Wendy Tan = 0%

