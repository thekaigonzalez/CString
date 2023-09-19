introduces a new String type which allows you to perform abritrary string operations.

supports:
    * splitting strings
    * adding characters
    * freeing strings from memory
    * string length
    * initializing strings

functions:
    void str_init
        (String *);

    void str_add_char
        (String *, char _ns);

    int str_length
        (String *);

    char *str_get
        (String *);

    void str_free
        (String *);

    char **str_split
        (String *, char _SEP);

    char str_at
        (String *, int);

specs:
    the maximum amount of characters which a string supports is implementation
    defined; the average amount (which can be improved - found in `string.h' is
    128). as far as splitting goes, the maximum amount of indices is 64. but can
    be improved, these limits were made strict on purpose, mainly for testing
    purposes.

how it works:
    when you create a string, it is not initialized by default. meaning that the
    internal character array has no real memory. the way to initialize this
    array is by using `str_init', then, once you no longer need this string, using `str_free`.

    You can check if a string is no longer available by using the macro (funny
    name ik) `str_iskilled(str)`; or by checking if the string length is -1.

    All strings will mostly start at 0. In essence each string isn't really a
    "true" string, meaning they are all arrays that are at a certain index which
    is changed depending on how many characters are inside of said string. This
    rhythm works by synchronizing a variable called `p', with the current
    character that is available and the ability to move to the next character
    within the array.

    For example, let's showcase the creation of a simple string, "Hello!":
        { 'H', 'e', 'l', 'l', 'o', '!' };

    After initializing the string, you have a freeload of memory and an index at 0. Let `0' be "H"

    {   'H'   }
    {    0    }

    With the String type, this is very simple to do. Just initialize the string
    and add the character. You will NOT have to worry about the index syncing
    with the current position of the array.

    String s;               /* New string */
    str_init (&s);          /* Initialize string, position 0 */

    And to add 'H' as the first character, simply use the library to add the
    character and it will also move the index to the next available position.

    str_add_char (&s, 'a');

    This function will not output anything, but our array and position look
    something similar to this:

    Characters: { 'H', '\0' }
    Indexes:    {  0 ,  1   }

    Notice how the index is set for the null terminator? when you continue to
    add more characters, the newly added character will replace the NULL
    terminator in exchange for the character, moving the index to the next
    position and adding the NULL terminator there, until you have an entire
    string completed.

    Knowing this now, you can simply add more characters to the array until you have an entire string.

    str_add_char (&s, 'e');
    str_add_char (&s, 'l');
    str_add_char (&s, 'l');
    str_add_char (&s, 'o');
    str_add_char (&s, '!');

    And like so, you have an entire string. That's how simple this library is.
    You can easily import this header into any one of your codebases without any
    hassle whatsoever. Lua implementations will be worked on soon but blame the
    lazy developer. (me)

license:
    This project is licensed under the "DO WHATEVER THE FUCK YOU WANT TO".... public license
