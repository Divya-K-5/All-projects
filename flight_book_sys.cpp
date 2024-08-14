#include <iostream>
#include <string>
#include <iomanip>
#include <vector> 
#include <algorithm> 
#include <limits> 


using namespace std;

class Flight
{   public:
    Flight(const string& cn, const string& fno, const string& src, const string& des, const string& dpr, const string& arr, int totseats, float cost)
        :cn(cn),
        fno(fno),
        src(src),
        des(des),
        dpr(dpr),
        arr(arr),
        totseats(totseats),
        avaseats(totseats),
        cost(cost),
        bkdseats(0)
    {   seats.reserve(totseats); 
		for (int i = 0; i < totseats; ++i)
		{   seats.push_back(false); }
    }
    
    string getSrc() const { return src; } 
	string getDes() const { return des; }
    int getTotSeats() const {   return totseats;    }
    string getFNo() const { return fno; }
    string getCN() const { return cn; }
   

    bool bookTicket(int sno)
    {   if(sno>=1 && sno<=totseats && !seats[sno-1])
        {   seats[sno-1]=true;
            avaseats-=1;
            bkdseats+=1;
            return true;    }
        return false;   
    }
    
        
    bool cancelTicket(int sno)
    {   if(sno>=1 && sno<=totseats && seats[sno-1])
        {   seats[sno-1]=false;
            avaseats+=1;
            bkdseats-=1;
            return true;    }
        return false;   
    }
    
    void flightInfo() const
	{   cout.setf(ios::left);
		cout <<"\t\t\t"<<setw(10)<<cn<<"\t"<<setw(10)<<src<<"\t"<<setw(10)<<des<<endl;
		cout <<"\t\t\t"<<setw(10)<<fno<<"\t"<<setw(10)<<dpr<<"\t"<<setw(10)<<arr<<"\tRs."<<cost<<endl;
		cout << "\n\t\t\tTotal Seats: " << totseats << endl; 
		cout <<"\t\t\t"<<"Availabale Seats: "<<avaseats<< endl; 
	
	} 
	
    void availableSeats() const
	{ 
		cout << "\t\t\tAvailable Seats on Flight " << fno<<":"<<endl;
		cout << "\t\t\t-----------------------------------"<<endl;
		for (int i = 0; i < 15; ++i) 
		{   cout.width(3);
		    cout<<"\t\t\t"; 
		    if (!seats[i]) 
		    {   cout << i + 1<<"\t";    }
		    else
		    {   cout<<"NA"<<"\t";}
		    if(i%3==2)
		        cout<<"\n";
		} 
	}
    
    
    
    private:
    string cn, fno, src, des, dpr, arr;
    int totseats, avaseats, bkdseats;
    float cost;
    vector <bool> seats;
};

class Ticket { 
public: 
	Ticket(const string& pName, int sno, Flight& f) 
		: pName(pName) 
		, sno(sno) 
		, f(f) 
	{ 
	} 

	string getPName() const{   return pName;   } 
	int getSNo() const { return sno; } 
	const Flight& getF() const { return f; } 

private: 
	string pName; 
	int sno; 
	Flight f; 
}; 

class User { 
public: 
	User(const string& uname, const string& pass) 
		: uname(uname) 
		, pass(pass) 
	{ 
	} 

	string getUName() const { return uname; } 
	string getPass() const { return pass; } 
	void addTicket(Ticket& newTicket) 
	{ 
		tickets.push_back(newTicket); 
	} 

	void removeTicket(int index) 
	{ 
		vector<Ticket>::iterator i = tickets.begin(); 
		i = i + index - 1; 
		tickets.erase(i); 
	} 

	void printAllTickets() const
	{ 
		int i = 0; 
		for (i = 0; i < tickets.size(); i++) { 
			cout << "\n\t\t------ Ticket " << i + 1 
				<< " ------" << endl; 
			cout << "\t\t\tPassenger: "
				<< tickets[i].getPName() << endl; 
			cout << "\t\t\t"<< tickets[i].getF().getCN()<<" Flight ("<< tickets[i].getF().getSrc() 
				<< " to "
				<< tickets[i].getF().getDes() 
				<< ")\n"; 
			cout << "\t\t\tFlight Number: "
				<< tickets[i].getF().getFNo() 
				<< endl; 
			cout << "\t\t\tSeat Number: "
				<< tickets[i].getSNo() << endl; 
		} 
	} 

	int numberOfTickets() const { return tickets.size(); } 
	Ticket& getTicket(int index){   return tickets[index - 1];  } 

private: 
	string uname; 
	string pass; 
	vector<Ticket> tickets; 
}; 


class FlightBookingSystem { 
public: 
	FlightBookingSystem() 
	{ 
		// Sample routes 
		f.push_back( 
			Flight("NetJets", "NJ0101", "Chennai", "Bangalore", "06:00", "07:30", 15, 2000.00));
		f.push_back( 
			Flight("NetJets", "NJ0102", "Bangalore", "Chennai", "08:00", "09:30", 15, 2000.00)); 
		f.push_back( 
			Flight("Jet Linx", "JL0201", "Bangalore", "Chennai",  "11:00", "12:30", 15, 2500.00));
		f.push_back( 
			Flight("Jet Linx", "JL0202", "Chennai", "Bangalore", "16:00", "17:30", 15, 2500.00));
		f.push_back( 
			Flight("NetJets", "NJ0103", "Chennai", "Delhi", "10:00", "12:00", 15, 3000.00));
		f.push_back( 
			Flight("Wheels Up", "WU0301", "Delhi", "Chennai",  "14:00", "16:00", 15, 4000.00));
		f.push_back( 
			Flight("Wheels Up", "WU0302", "Chennai", "Delhi", "20:00", "22:00", 15, 4000.00));
		f.push_back( 
			Flight("Wheels Up", "WU0303", "Delhi", "Chennai",  "07:00", "09:00", 15, 4000.00));
		f.push_back( 
			Flight("Jet Linx", "JL0203", "Bangalore", "Delhi",  "13:00", "14:30", 15, 2500.00));
		f.push_back( 
			Flight("Jet Linx", "JL0204", "Delhi", "Bangalore", "15:00", "16:30", 15, 2500.00));
		
		} 

	void registerUser(const string& uname, 
					const string& pass) 
	{ 
		users.push_back(User(uname, pass)); 
		cout << "\n\t\t\tUser registered successfully.\n\t\t\tPlease login to continue!\n"; 
	} 

	bool authenticateUser(const string& uname, 
						const string& pass) 
	{ 
		for (const User& user : users) { 
			string lowercaseUsername = user.getUName(); 
			string lowercaseInputUsername = uname; 
			transform(lowercaseUsername.begin(), 
					lowercaseUsername.end(), 
					lowercaseUsername.begin(), ::tolower); 
			transform(lowercaseInputUsername.begin(), 
					lowercaseInputUsername.end(), 
					lowercaseInputUsername.begin(), 
					::tolower); 

			if (lowercaseUsername == lowercaseInputUsername 
				&& user.getPass() == pass) { 
				return true; 
			} 
		} 
		return false; 
	} 

	User& findUser(string uname) 
	{ 
		for (int i = 0; i < users.size(); i++) { 
			if (users[i].getUName() == uname) { 
				return users[i]; 
			} 
		} 
		return users[users.size() - 1]; 
	} 

	
	void displayFlights() const
	{   string s,d;
		cout<<"\t\t\tEnter source:\t";
		cin>>s;
		cout<<"\t\t\tEnter destination:\t";
		cin>>d;
		cout<<"\n";
		for (int i = 0; i < f.size(); i++) { 
			if (f[i].getSrc()==s && f[i].getDes()==d) { 
				f[i].flightInfo(); 
				cout << endl; 
			} 
		} 
	} 

	void bookTicket(const string& uname) 
	{ 
		int selectedf, selectedSeat; 

		displayFlights(); 
		cout << "\n\t\t\tSelect a Flight (Enter the Flight "
				"Number): "; 
		string FNumber; 
		cin >> FNumber; 

		bool validf = false; 
		for (int i = 0; i < f.size(); i++) { 
			if (FNumber == f[i].getFNo()) { 
				selectedf = i ; 
				validf = true; 
				break; 
			} 
		} 

		if (!validf) { 
			cout << "\n\tInvalid flight number. Please "
					"enter a valid flight number.\n"; 
			return; // Return to the main menu 
		} 

		// Consume the newline character 
		cin.ignore( 
			std::numeric_limits<std::streamsize>::max(), 
			'\n'); 

		
        f[selectedf].availableSeats();
		cout << "\n\t\t\tEnter the seat number you want to "
				"book: "; 
		cin >> selectedSeat; 

		if (cin.fail() || selectedSeat < 1 
			|| selectedSeat > f[selectedf] 
								.getTotSeats()) { 
			cout << "\n\tInvalid seat number. Please enter a valid seat number for the selected flight.\n"; 
			return; // Return to the main menu 
		} 

		if (f[selectedf].bookTicket( 
				selectedSeat)) { 
			Ticket ticket(uname, selectedSeat, f[selectedf]); 
			User& user = findUser(uname); 
			user.addTicket(ticket); 
			cout << "\n\t\t\tTicket booked successfully!\n"; 
			cout << "\t\t\tPassenger: "
				<< ticket.getPName() << "\n"; 
			cout << "\t\t\tFlight Number: "
				<< f[selectedf].getFNo() 
				<< "\n"; 
			cout << "\t\t\tRoute: "<< ticket.getF().getSrc() << " to "<< ticket.getF().getDes() 
				<< "\n"; 
			cout << "\t\t\tSeat Number: "
				<< ticket.getSNo() << "\n"; 
		} 
		else { 
			cout << "\n\tSeat booking failed. The seat is "
					"already reserved or does not exist.\n"; 
		} 
	} 

	void cancelTicket(const string& username) 
	{ 
		int ticketDel = -1; 
		User& user = findUser(username); 
		if (user.numberOfTickets() <= 0) { 
			cout << "\n\t\t\tNo Tickets Booked!\n"; 
			return; 
		} 
		user.printAllTickets(); 

		cout << "\n\t\t\tSelect the ticked to be "
				"cancelled... "; 
		cin >> ticketDel; 

		// Consume the newline character 
		cin.ignore( 
			std::numeric_limits<std::streamsize>::max(), 
			'\n'); 

		if (cin.fail() 
			|| ticketDel > user.numberOfTickets()) { 
			cout << "\tInvalid Ticked Selected! Please "
					"select a valid ticket\n"; 
			return; 
		} 
		else { 
			cout << "\t\t\tTicket canceled successfully.\n"; 
			Ticket ticket = user.getTicket(ticketDel); 
			Flight fli = ticket.getF(); 
			for (int i = 0; i < f.size(); i++) { 
				if (f[i].getFNo() 
					== fli.getFNo()) { 
					f[i].cancelTicket( 
						ticket.getSNo()); 
				} 
			} 
			user.removeTicket(ticketDel); 
		} 
	} 

	void run() 
	{ 
		while (true) { 
			cout << "\n\t------ Welcome to the Flight Booking System------\n\n"; 
			cout << "\t\t\t1. Register\n\t\t\t2. Log "
					"In\n\t\t\t3. Exit\t\t\t\n"; 
			cout << "\n\t\t\tEnter your choice: "; 
			int choice; 
			cin >> choice; 

			if (choice == 1) { 
				string username, password; 
				cout << "\n\t\t\tEnter username: "; 
				cin >> username; 
				cout << "\t\t\tEnter password: "; 
				cin >> password; 
				registerUser(username, password); 
			} 
			else if (choice == 2) { 
				string username, password; 
				cout << "\n\t\t\tEnter username: "; 
				cin >> username; 
				cout << "\t\t\tEnter password: "; 
				cin >> password; 
				if (authenticateUser(username, password)) { 
					cout << "\n\t\t\tLogged in "
							"successfully!\n"; 
					userMenu(username); 
				} 
				else { 
					cout << "\n\t\t\tAuthentication failed!\n\t\t\tPlease check your username "
							"and password.\n"; 
				} 
			} 
			else if (choice == 3) { 
				cout << "\n\t\t\tExiting the Flight Booking System. Goodbye!\n"; 
				break; 
			} 
		} 
	} 

	void userMenu(string username) 
	{ 
		int choice = 0;
		bool flag=true;
		while (true) { 
			cout << "\n\t----------- Welcome to the User "
					"Menu ------------\n\n"; 
			cout << "\t\t\t1. BookTicket\n\t\t\t2. Cancel "
					"Ticket\n\t\t\t3. Logout\n"; 
			cout << "\n\t\t\tEnter your choice: "; 
			cin >> choice; 
            switch(choice){
			case 1:    
				bookTicket(username);
				break;
			case 2:	
			    cancelTicket(username); 
			    break;
			case 3:
			    cout<< "\n\t\t\tLogged out successfully.\n"; 
			    flag=false;
				break; 
			}} 
		} 
	

private: 
	vector<User> users; 
	vector<Flight> f; 
	
}; 




int main() 
{ 
	FlightBookingSystem system; 
	system.run(); 
	return 0; 
}
