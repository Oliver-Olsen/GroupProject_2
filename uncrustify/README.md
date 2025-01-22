## Uncrustify guide

Uncrustify is a tool for easily beautifying the source code



## Syntax for preventing uncustify from modifying certain sections

Syntax for disabling uncrustify
```shell
/* *UNCRUSTIFY-OFF* */
```

It's important always to enable uncrustify again after at the end of the section.

Syntax for enabling uncrustify
```shell
/* *UNCRUSTIFY-ON* */
```

Example code:
```shell
Foo()
{
	some code

	/* *UNCRUSTIFY-OFF* */
	some other code that should NOT be uncrustifyed

	/* *UNCRUSTIFY-ON* */
}
```


## Uncrustify from PowerShell:


```shell
PS GitProjectPath\uncrustify> py uncrustify_file_list.py
```

Different style:

```shell
PS GitProjectPath\uncrustify> uncrustify -c uncrustify.cfg --no-backup -F uncrustify_files.txt
```

```shell
PS GitProjectPath\uncrustify> uncrustify -c kr-indent.cfg --no-backup -F uncrustify_files.txt
```

```shell
PS GitProjectPath\uncrustify> uncrustify -c klaus.cfg --no-backup -F uncrustify_files.txt
```

**Each cfg file in the directory represent a style**


## Misc links

https://wiki.libav.org/CodingStyle/Uncrustify

https://github.com/Coding-With-The-Force/SalesforceBestPractices/blob/master/uncrustify.cfg

https://github.com/uncrustify/uncrustify

https://en.wikipedia.org/wiki/Indentation_style#Allman_style

