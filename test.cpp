static int num5;
  public static final int CONSTANT = 1;

  public int NUM1; // violation
  public int NUM1; // violation 'Name 'NUM1' must match pattern'

  protected int NUM2; // violation
  protected int NUM2; // violation 'Name 'NUM2' must match pattern'

  int NUM3; // violation
  int NUM3; // violation 'Name 'NUM3' must match pattern'

  private int NUM4; // violation
  private int NUM4; // violation 'Name 'NUM4' must match pattern'

}
</code></pre></div>
@@ -116,11 +116,11 @@ class Example1 {
        <p id="Example2-code">Code Example:</p>
        <div class="wrapper"><pre class="prettyprint"><code class="language-java">
class Example2 {
  public int num1; // violation
  public int num1; // violation 'Name 'num1' must match pattern'

  protected int num2;
  int num3;
  private int num4; // violation
  private int num4; // violation 'Name 'num4' must match pattern'

}
</code></pre></div>
@@ -142,9 +142,9 @@ class Example2 {
        <div class="wrapper"><pre class="prettyprint"><code class="language-java">
class Example3 {
  public int NUM1;
  protected int NUM2; // violation
  protected int NUM2; // violation 'Name 'NUM2' must match pattern'

  int NUM3; // violation
  int NUM3; // violation 'Name 'NUM3' must match pattern'

  private int NUM4;
}
  1 change: 0 additions & 1 deletion1  
src/test/java/com/puppycrawl/tools/checkstyle/bdd/InlineConfigParser.java
Original file line number	Diff line number	Diff line change
@@ -272,7 +272,6 @@ public final class InlineConfigParser {
            "com.puppycrawl.tools.checkstyle.checks.naming.InterfaceTypeParameterNameCheck",
            "com.puppycrawl.tools.checkstyle.checks.naming.LocalFinalVariableNameCheck",
            "com.puppycrawl.tools.checkstyle.checks.naming.LocalVariableNameCheck",
            "com.puppycrawl.tools.checkstyle.checks.naming.MemberNameCheck",
            "com.puppycrawl.tools.checkstyle.checks.naming.MethodNameCheck",
            "com.puppycrawl.tools.checkstyle.checks.naming.MethodTypeParameterNameCheck",
            "com.puppycrawl.tools.checkstyle.checks.naming.PackageNameCheck",
  8 changes: 4 additions & 4 deletions8  
...t/resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberName.java
Original file line number	Diff line number	Diff line change
@@ -18,8 +18,8 @@ public class InputMemberName
    int mPackage;//comment
    private int mPrivate;

    public int _public; // violation
    protected int _protected; // violation
    int _package; // violation
    private int _private; // violation
    public int _public; // violation 'Name '_public' must match pattern'
    protected int _protected; // violation 'Name '_protected' must match pattern'
    int _package; // violation 'Name '_package' must match pattern'
    private int _private; // violation 'Name '_private' must match pattern'
}
  8 changes: 4 additions & 4 deletions8  
.../resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberName2.java
Original file line number	Diff line number	Diff line change
@@ -13,10 +13,10 @@

public class InputMemberName2
{
    public int mPublic; // violation
    protected int mProtected; // violation
    int mPackage; // violation
    private int mPrivate; // violation
    public int mPublic; // violation 'Name 'mPublic' must match pattern'
    protected int mProtected; // violation 'Name 'mProtected' must match pattern'
    int mPackage; // violation 'Name 'mPackage' must match pattern'
    private int mPrivate; // violation 'Name 'mPrivate' must match pattern'

    public int _public;
    protected int _protected;
  2 changes: 1 addition & 1 deletion2  
.../resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberName3.java
Original file line number	Diff line number	Diff line change
@@ -13,7 +13,7 @@

public class InputMemberName3
{
    public int mPublic; // violation
    public int mPublic; // violation 'Name 'mPublic' must match pattern'
    protected int mProtected;
    int mPackage;//comment
    private int mPrivate;
  2 changes: 1 addition & 1 deletion2  
.../resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberName4.java
Original file line number	Diff line number	Diff line change
@@ -14,7 +14,7 @@
public class InputMemberName4
{
    public int mPublic;
    protected int mProtected; // violation
    protected int mProtected; // violation 'Name 'mProtected' must match pattern'
    int mPackage;//comment
    private int mPrivate;

  2 changes: 1 addition & 1 deletion2  
.../resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberName5.java
Original file line number	Diff line number	Diff line change
@@ -15,7 +15,7 @@ public class InputMemberName5
{
    public int mPublic;
    protected int mProtected;
    int mPackage; // violation
    int mPackage; // violation 'Name 'mPackage' must match pattern'
    private int mPrivate;

    public int _public;
  2 changes: 1 addition & 1 deletion2  
.../resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberName6.java
Original file line number	Diff line number	Diff line change
@@ -16,7 +16,7 @@ public class InputMemberName6
    public int mPublic;
    protected int mProtected;
    int mPackage;//comment
    private int mPrivate; // violation
    private int mPrivate; // violation 'Name 'mPrivate' must match pattern'

    public int _public;
    protected int _protected;
  6 changes: 3 additions & 3 deletions6  
.../resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberName7.java
Original file line number	Diff line number	Diff line change
@@ -18,8 +18,8 @@ public class InputMemberName7
    int mPackage;//comment
    private int mPrivate;

    public int _public; // violation
    protected int _protected; // violation
    int _package; // violation
    public int _public; // violation 'Name '_public' must match pattern'
    protected int _protected; // violation 'Name '_protected' must match pattern'
    int _package; // violation 'Name '_package' must match pattern'
    private int _private;
}
  68 changes: 34 additions & 34 deletions68  
...ces/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberNameExtended.java
Original file line number	Diff line number	Diff line change
@@ -16,38 +16,38 @@

public class InputMemberNameExtended
{
    public int mPublic; // violation
    protected int mProtected; // violation
    int mPackage; // violation
    private int mPrivate; // violation
    public int mPublic; // violation 'Name 'mPublic' must match pattern'
    protected int mProtected; // violation 'Name 'mProtected' must match pattern'
    int mPackage; // violation 'Name 'mPackage' must match pattern'
    private int mPrivate; // violation 'Name 'mPrivate' must match pattern'

    public int _public; // violation
    protected int _protected; // violation
    int _package; // violation
    private int _private; // violation
    public int _public; // violation 'Name '_public' must match pattern'
    protected int _protected; // violation 'Name '_protected' must match pattern'
    int _package; // violation 'Name '_package' must match pattern'
    private int _private; // violation 'Name '_private' must match pattern'

    class Inner {
        public int mPublic; // violation
        protected int mProtected; // violation
        int mPackage; // violation
        private int mPrivate; // violation

        public int _public; // violation
        protected int _protected; // violation
        int _package; // violation
        private int _private; // violation
        public int mPublic; // violation 'Name 'mPublic' must match pattern'
        protected int mProtected; // violation 'Name 'mProtected' must match pattern'
        int mPackage; // violation 'Name 'mPackage' must match pattern'
        private int mPrivate; // violation 'Name 'mPrivate' must match pattern'

        public int _public; // violation 'Name '_public' must match pattern'
        protected int _protected; // violation 'Name '_protected' must match pattern'
        int _package; // violation 'Name '_package' must match pattern'
        private int _private; // violation 'Name '_private' must match pattern'
    }

    Inner anon = new Inner() {
        public int mPublic; // violation
        protected int mProtected; // violation
        int mPackage; // violation
        private int mPrivate; // violation

        public int _public; // violation
        protected int _protected; // violation
        int _package; // violation
        private int _private; // violation
        public int mPublic; // violation 'Name 'mPublic' must match pattern'
        protected int mProtected; // violation 'Name 'mProtected' must match pattern'
        int mPackage; // violation 'Name 'mPackage' must match pattern'
        private int mPrivate; // violation 'Name 'mPrivate' must match pattern'

        public int _public; // violation 'Name '_public' must match pattern'
        protected int _protected; // violation 'Name '_protected' must match pattern'
        int _package; // violation 'Name '_package' must match pattern'
        private int _private; // violation 'Name '_private' must match pattern'
    };
}

@@ -71,15 +71,15 @@ enum Direction {
    EAST(-2),
    WEST(2);

    public int mPublic = 0; // violation
    int mProtected = 0; // violation
    int mPackage = 0; // violation
    int mPrivate = 0; // violation
    public int mPublic = 0; // violation 'Name 'mPublic' must match pattern'
    int mProtected = 0; // violation 'Name 'mProtected' must match pattern'
    int mPackage = 0; // violation 'Name 'mPackage' must match pattern'
    int mPrivate = 0; // violation 'Name 'mPrivate' must match pattern'

    public int _public = 0; // violation
    int _protected = 0; // violation
    int _package = 0; // violation
    int _private = 0; // violation
    public int _public = 0; // violation 'Name '_public' must match pattern'
    int _protected = 0; // violation 'Name '_protected' must match pattern'
    int _package = 0; // violation 'Name '_package' must match pattern'
    int _private = 0; // violation 'Name '_private' must match pattern'

    Direction(int code){
        this.code=code;
  2 changes: 1 addition & 1 deletion2  
...ources/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberNameInner.java
Original file line number	Diff line number	Diff line change
@@ -60,7 +60,7 @@ public static void main()
        {
            private static final int CDS = 1;

            private int ABC; // violation
            private int ABC; // violation 'Name 'ABC' must match pattern
        };
     }

  2 changes: 1 addition & 1 deletion2  
...es/com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberNameSimpleOne.java
Original file line number	Diff line number	Diff line change
@@ -38,7 +38,7 @@ final class InputMemberNameSimpleOne
    private static int sNumCreated = 0;

    /** Invalid format **/
    private int badMember = 2; // violation
    private int badMember = 2; // violation 'Name 'badMember' must match pattern
    /** Valid format **/
    private int mNumCreated1 = 0;
    /** Valid format **/
  2 changes: 1 addition & 1 deletion2  
.../com/puppycrawl/tools/checkstyle/checks/naming/membername/InputMemberNameSimpleThree.java
Original file line number	Diff line number	Diff line change
@@ -47,5 +47,5 @@ enum MyEnum1
    XYZ;

    /** Should be mSomeMember */
    private int someMember; // violation
    private int someMember; // violation 'Name 'someMember' must match pattern
}
  2 changes: 1 addition & 1 deletion2  
src/test/resources/com/puppycrawl/tools/checkstyle/grammar/InputGrammar.java
Original file line number	Diff line number	Diff line change
@@ -15,5 +15,5 @@
 */
public class InputGrammar
{
    int ÃЯ = 1; // illegal, unless UTF-8 // violation
    int ÃЯ = 1; // illegal, unless UTF-8 // violation 'Name 'ÃЯ' must match pattern'
}
  8 changes: 4 additions & 4 deletions8  
...examples/resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/Example1.java
Original file line number	Diff line number	Diff line change
@@ -18,13 +18,13 @@ class Example1 {
  static int num5;
  public static final int CONSTANT = 1;

  public int NUM1; // violation
  public int NUM1; // violation 'Name 'NUM1' must match pattern'

  protected int NUM2; // violation
  protected int NUM2; // violation 'Name 'NUM2' must match pattern'

  int NUM3; // violation
  int NUM3; // violation 'Name 'NUM3' must match pattern'

  private int NUM4; // violation
  private int NUM4; // violation 'Name 'NUM4' must match pattern'

}
// xdoc section -- end
  4 changes: 2 additions & 2 deletions4  
...examples/resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/Example2.java
Original file line number	Diff line number	Diff line change
@@ -13,11 +13,11 @@

// xdoc section -- start
class Example2 {
  public int num1; // violation
  public int num1; // violation 'Name 'num1' must match pattern'

  protected int num2;
  int num3;
  private int num4; // violation
  private int num4; // violation 'Name 'num4' must match pattern'

}
// xdoc section -- end
  4 changes: 2 additions & 2 deletions4  
...examples/resources/com/puppycrawl/tools/checkstyle/checks/naming/membername/Example3.java
Original file line number	Diff line number	Diff line change
@@ -13,9 +13,9 @@
// xdoc section -- start
class Example3 {
  public int NUM1;
  protected int NUM2; // violation
  protected int NUM2; // violation 'Name 'NUM2' must match pattern'

  int NUM3; // violation
  int NUM3; // violation 'Name 'NUM3' must match pattern'

  private int NUM4;
}