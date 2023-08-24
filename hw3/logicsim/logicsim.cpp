#include <iostream>
#include <sstream>
#include <string>

#include "circuit.h"

using namespace std;

int main(int argc, char* argv[])
{
	stringstream ss;
  Circuit C;

  if(argc != 1)
  {
    if(C.parse(argv[1]))
    {
        cout<<" ~~~~ starting  C.startUml(ss);"<<endl;
    	  C.startUml(ss);
        cout<<" ~~~~ finished  C.startUml(ss);"<<endl;
        C.run(ss);
        cout<<" ~~~~ finished  C.run(ss);"<<endl;
        C.endUml(ss);
        cout<<" ~~~~ finished  C.enduml(ss);"<<endl;
        cout << ss.str() << endl;
    }
  }
  else
  {
      cout << "Please provide a circuit file to simulate." << endl;
      return 1;
  }
}
