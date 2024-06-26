# utils

## trans

This is a bash command line tool to translate between english & french. It uses the DeepL API. To use this you will need a DeepL API Account.

Mac users: This requires bash version 5 which you can install with brew: `brew install bash`.

Sign up for a free [DeepL API account here](https://www.deepl.com/pro?cta=header-prices).

Then get a DEEPL access token and set it in your env, like `$ export DEEPL_KEY=abc-123-xxx-...`
Also the key can be provided on the command line.

General usage:
```
Usage: trans [-iecd -k key] "du texte en français"

Translates the given French text to English

Options:
  -e     : The given text is in English, translate to French
  -k key : Use this DEEPL authorization key
  -i     : read text from standard in. Ignores command line
  -c     : copy translated text to clipboard
  -L     : Read continuosly from stdin. Line-by-Line.
  -d     : Debug mode
  -h : print this help message
  ```
  
  A recommended way to run the tool is with an in interactive mode, start with "-L" . This gives you an interactive prompt. It supports history, use "up/down-arrow" and typical command line history navigation (e.g. ^r to search).  History is saved in ~/.trans_history 
  
  Example:
  ```
  $ ./trans -L
Enter  .e to prompt English
       .f to prompt french.
       .F toggle french formality (tu vs vous)
       .p paste in next sentence.
       .d to toggle debug
       .h for this help
       .c copy last translation to pb
      .q or ^d to quit.
fr> 
```
Example session with `trans -L`:
```
fr> S'agit il de quoi
"What is it about"
fr> .e
eng> What is it about
"De quoi s'agit-il ?"
eng> .f
fr> De quoi s'agit-il ?
"What is it about?"
fr> .e
eng> What is it about?
"De quoi s'agit-il ?"
eng> How are you doing ?
"Comment allez-vous ?"
eng> .F
Formality is now tu
eng> How are you doing ?
"Comment vas-tu ?"
eng>
```
Note on the mac only it support copy / paste to the clipboard.

## xid

This is a role-your-own sudo.
Build:
```bash
$ gcc -o xid xid.c
$ sudo chown root xid
$ sudo 6755 xid
```
Then it can be used just like sudo.
And yes it is a security nightmare. Use at your own risk.


