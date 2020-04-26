#include <stdio.h>

$wallet = 150;

sub testFunc1 {
	return $wallet;
}

sub staticScoping {
	my $wallet = 3000; #static scoping uses "my" keyword
	return testFunc1();
}

#This output is using static scoping. The output is 150 instead of 3000
#because static/lexical scoping using "my" in Perl guarantees privacy. Assuming 
#you don't hand out references to these private variables that would let them be 
#changed indirectly, you can be certain that every possible access to these 
#private variables is restricted to code within one discrete and easily identifiable
#section of your program. These lexically scoped variables are hidden from the world
#outside their immediately enclosing scope. They are hidden from subroutines called
#from their scope.
print "Static scoping: ", staticScoping(), "\n";

$credit = 500;

sub testFunc2 {
	return $credit;
}

sub dynamicScoping {
	local $credit = 700; #dynamic scoping uses "local" keyword
	return testFunc2();
}

#This output is using dynamic scoping. The output is 700 instead of 500
#because in Perl, using the "local" keyword operator on a global variable
#gives it temporary value each time local is executed, but it does not affect
#that variable's global visibility. When the program reaches the end of that 
#dynamic scope, this temporary value is discarded and the original value is restored.
#This means, calling testFunc2 inside the subroutine dynamicScoping will print 
#the temporarily changed value of $credit. The value depends on the scope 
#of the function it was called from.
print "Dynamic scoping: ", dynamicScoping(), "\n";

#The difference between the dynamic scoping described in this chapter and that 
#implemented in Perl is that Perl's dynamic scoping is based on where the 
#dynamic variable is declared. The book notes that dynamic scoping is based 
#on the order the subroutines are called.
