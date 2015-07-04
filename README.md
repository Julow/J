# J

Command line editing tool

#### Cursor

| Bindings			| |
|-------------------|----|
| ctrl+left<br>ctrl+right | Move the cursor by word<br>(`alt` can be used instead of `ctrl`) |
| ctrl+A<br>home	| Move the cursor at the start of the line |
| ctrl+E<br>end		| Move the cursor at the end of the line |

#### Clipboard

Cut are chained into the clipboard

| Bindings			| |
|-------------------|----|
| ctrl+Y			| Paste last cut |
| ctrl+V			| Paste last cut and remove it from the clipboard |
| ctrl+W			| Cut from the start of the word to the cursor |
| ctrl+K			| Cut from the cursor to the end of the line |
| ctrl+O			| Cut from the start of the line to the cursor |
| ctrl+X			| Cut the line |

#### History

| Bindings			| |
|-------------------|----|
| up<br>down		| Navigate into the history |
| ctrl+R			| History search |

#### Selection

**Pasting**, **deleting** or writing while selection
overwrite the selected text

Moving the cursor cancel the selection

| Bindings			| |
|-------------------|----|
| shift+left<br>shift+right | Select text |
| ctrl+X<br>ctrl+W	| Cut the selection |
| ctrl+shift+left<br>ctrl+shift+right | Select by word |

#### Tab completion

| Bindings			| |
|-------------------|----|
| tab				| Tab completion |
| shift+tab			| Tab completion (reversed) |

#### Misc

| Bindings			| |
|-------------------|----|
| ctrl+C			| Clear the line |
| ctrl+H			| Backspace by word |
| ctrl+delete		| Delete by word |
| ctrl+F			| Search and replace |
| ctrl+space		| Toggle J |
