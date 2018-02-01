void PRINT_VALUES()
{
    cout<<endl<<"VALUES IN REGISTERS :"<<endl<<endl;
    cout<<"A = "<<A<<endl;
    cout<<"B = "<<B<<endl;
    cout<<"C = "<<C<<endl;
    cout<<"D = "<<D<<endl;
    cout<<"E = "<<E<<endl;
    cout<<"H = "<<H<<endl;
    cout<<"L = "<<L<<endl;
    cout<<endl<<"VALUES OF FLAGS :"<<endl<<endl;
    cout<<"CARRY FLAG \t=\t "<<CF<<endl;
    cout<<"SIGN FLAG \t=\t "<<SF<<endl;
    cout<<"AUXILLAY FLAG \t=\t "<<AF<<endl;
    cout<<"PARITY FLAG \t=\t "<<PF<<endl;
    cout<<"ZERO FLAG \t=\t "<<ZF<<endl<<endl;
    if(memoindex != 0)
    {
        cout<<"MEMORY LOCATION USED"<<endl<<endl;
        for(int i=0;i<memoindex;i++)
        {
            cout<<memo[i].loc<<" : "<<memo[i].info<<endl;
        }
    }
}
