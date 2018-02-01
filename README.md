# 8085-SIMULATOR
Here, I have made and simulator of 8085 micrprocessor which runs almost all the basic commands

In this I implemented 8085 emulator with the following commnads :-

see this for reference:- http://scanftree.com/microprocessor/Instruction-Set-In-8085

Load and Store - MOV , MVI , LXI , LDA , STA , LHLD , SHLD , STAX , XCHG

Arithmetic - ADD , ADI , SUB , INR , DCR , INX , DCX , DAD , SUI

Logical - CMA , CMP

Branching - JMP , JC , JNC , JZ , JNZ

One Additional command SET should be made to set data into valid memory locations (Eg -
SET 2500,0A ).

I also implemented a debugger with the following commands:-

1. break or b `line no`:- It will set break point on given line number.

2. run or r :- Run the program until it ends or breakpoint is encountered.

3. step or s :- It will run the program one instruction at a time.

4. print or p:- It prints the value of register or memory location. for ex p A will print the value of register A. p x2500 will print the value at memory location x2500 if any.

5. quit or q:- quits the debugger.

6. help:- will show all the commandsof debugger.

Any one can run run this program with the following commands on the terminal
1.Program_Name Input_File_Name               (take input from file without running debugger)

2.Program_Name Input_File_Name Debugger      (take input from file with debugger)

3.Program_Name                               (take input from terminal without running debugger)

4.Program_Name Debugger                      (take input from terminal with debugger)


NOTE : Please Refer to the sample program given in input.txt


                                                            THANK YOU !
