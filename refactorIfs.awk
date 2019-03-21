# should work only with gawk

#next = skip to next line
match($0, /(\s*)if \((.+)\)/, arr) {print arr[1] "int hack_" NR " = " arr[2] ";\n" arr[1] "if (hack_" NR ")" ; next}
#matches everything
1 {print $0}
	  
