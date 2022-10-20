int main()
{
 const int i=90;

if constexpr (i) //'if constexpr' is part of C++17
{ cout<< "True!"; }
else
{ cout<<"False" ; }

cin.get();
return 0;
}
