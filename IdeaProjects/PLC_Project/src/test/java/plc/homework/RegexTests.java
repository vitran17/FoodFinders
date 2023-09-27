package plc.homework;


import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.regex.Pattern;
import java.util.stream.Stream;

/**
 * Contains JUnit tests for {@link Regex}. A framework of the test structure 
 * is provided, you will fill in the remaining pieces.
 *
 * To run tests, either click the run icon on the left margin, which can be used
 * to run all tests or only a specific test. You should make sure your tests are
 * run through IntelliJ (File > Settings > Build, Execution, Deployment > Build
 * Tools > Gradle > Run tests using <em>IntelliJ IDEA</em>). This ensures the
 * name and inputs for the tests are displayed correctly in the run window.
 */
public class RegexTests {

    /**
     * This is a parameterized test for the {@link Regex#EMAIL} regex. The
     * {@link ParameterizedTest} annotation defines this method as a
     * parameterized test, and {@link MethodSource} tells JUnit to look for the
     * static method {@link #testEmailRegex()}.
     *
     * For personal preference, I include a test name as the first parameter
     * which describes what that test should be testing - this is visible in
     * IntelliJ when running the tests (see above note if not working).
     */
    @ParameterizedTest
    @MethodSource
    public void testEmailRegex(String test, String input, boolean success) {
        test(input, Regex.EMAIL, success);
    }

    /**
     * This is the factory method providing test cases for the parameterized
     * test above - note that it is static, takes no arguments, and has the same
     * name as the test. The {@link Arguments} object contains the arguments for
     * each test to be passed to the function above.
     */
    public static Stream<Arguments> testEmailRegex() {
        return Stream.of(
                Arguments.of("Alphanumeric", "thelegend27@gmail.com", true),
                Arguments.of("UF Domain", "otherdomain@ufl.edu", true),
                Arguments.of("Yahoo", "hihihehe123@yahoo.com", true),
                Arguments.of("Business", "business@example.net", true),
                Arguments.of("Starbuck", "StarbuckscustomerIRL@eegroup.ie", true),
                Arguments.of("Missing Domain Dot", "missingdot@gmailcom", false),
                Arguments.of("Symbols", "symbols#$%@gmail.com", false),
                Arguments.of("Missing Domain Parts", "hihi2.com", false),
                Arguments.of("Missing username before @", "@gmail.com", false),
                Arguments.of("Not email", "hihi.com", false)

        );
    }

    @ParameterizedTest
    @MethodSource
    public void testEvenStringsRegex(String test, String input, boolean success) {
        test(input, Regex.EVEN_STRINGS, success);
    }

    public static Stream<Arguments> testEvenStringsRegex() {
        return Stream.of(
                //what has ten letters and starts with gas?
                Arguments.of("10 Characters", "automobile", true),
                Arguments.of("14 Characters", "i<3pancakes10!", true),
                Arguments.of("12 Characters", "homnaytroioi", true),
                Arguments.of("16 Characters","#khongbietvietgi", true),
                Arguments.of("20 Characters","kh#a_sj!sj%djn&><?;)", true),
                Arguments.of("6 Characters", "6chars", false),
                Arguments.of("13 Characters", "i<3pancakes9!", false),
                Arguments.of("1 characters", "1", false),
                Arguments.of("21 Characters", ".....................",false),
                Arguments.of("17 Characters", "(mitmapcutehatme)", false)
        );
    }

    @ParameterizedTest
    @MethodSource
    public void testIntegerListRegex(String test, String input, boolean success) {
        test(input, Regex.INTEGER_LIST, success);
    }

    public static Stream<Arguments> testIntegerListRegex() {
        return Stream.of(
                Arguments.of("Single Element", "[1]", true),
                Arguments.of("Multiple Elements", "[1,2,3]", true),
                Arguments.of("Multiple elements" ,"[1, 2]", true),
                Arguments.of("Multiple elements", "[1 ,2]", true),
                Arguments.of("Empty", "[]", true),
                Arguments.of("Missing Brackets", "1,2,3", false),
                Arguments.of("Missing Commas", "[1 2 3]", false),
                Arguments.of("Missing Bracket", "[1, 2", false),
                Arguments.of("Missing Commas", "[1 2, 3 4]", false),
                Arguments.of("Invalid", "[,2]", false)
        );
    }

    @ParameterizedTest
    @MethodSource
    public void testNumberRegex(String test, String input, boolean success) {
        test(input, Regex.NUMBER, success); //TODO
    }


    public static Stream<Arguments> testNumberRegex() {
        return Stream.of(
                Arguments.of("Single Number", "1", true),
                Arguments.of("Decimal Number", "123.456", true),
                Arguments.of("Negative Number", "-1.0", true),
                Arguments.of("Decimal Number", "12.1", true),
                Arguments.of("Positive number", "+1.0", true),
                Arguments.of("Missing Number", "1.", false),
                Arguments.of("Missing Number", ".5", false),
                Arguments.of("Missing Number", "+.4", false),
                Arguments.of("Missing Number", "-.1", false),
                Arguments.of("Missing Number","..1",false)
        );
    }

    @ParameterizedTest
    @MethodSource
    public void testStringRegex(String test, String input, boolean success) {
        test(input, Regex.STRING, success); //TODO
    }

    public static Stream<Arguments> testStringRegex() {
        return Stream.of(
                Arguments.of("Double Quote", "\"\"", true),
                Arguments.of("String and comma", "\"Hello, World!\"", true),
                Arguments.of("String", "\"Hello\"", true),
                Arguments.of("Valid", "\"1\\t2\"", true),
                Arguments.of("Comma","\",\"", true ),

                Arguments.of("Missing Double Quote", "\"unterminated", false),
                Arguments.of("Missing Double Quote", "cute123\"", false),
                Arguments.of("Extra Double Quote", "\"hihi\"\"", false),
                Arguments.of("Invalid", "\"invalid\\escape\"", false),
                Arguments.of("Invalid", "\"", false)

        );//TODO
    }

    /**
     * Asserts that the input matches the given pattern. This method doesn't do
     * much now, but you will see this concept in future assignments.
     */
    private static void test(String input, Pattern pattern, boolean success) {
        Assertions.assertEquals(success, pattern.matcher(input).matches());
    }

}
