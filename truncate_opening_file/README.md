truncate_opening_file
============

Environment
-
Already test in Ubuntu 12.04

Result
-
> $ ./truncate_opening_file  
open and mmap by parent success  
open by child successful  

Conclusions
-
 - Unlike Windows we could truncate a file even though the file had already open
