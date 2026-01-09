#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;





//Data
int game_counter=5 ,delete_counter, function_choice=0 , new_index,  cart_counter=0 ;


double discount=5;
double sum=0.0;
bool game_deleted=false;

struct Inventory
{
    string NAME;
    double PRICE;
};

Inventory game[50]={
    {"Black Myth: Wukong", 50.1},
        {"Monster Hunter Wilds", 45.9},
        {"HELlDIVERS 2", 80.0},
        {"GTA V", 96.7},
        {"Rust", 74.3}
};




//Struct for storing user selected games on chechkout
struct Cart
{
    string name;
    double price;
};

Cart cart[50];







void updateDiscount()
{
    char Choice;
    cout<<"Current discount offer on more than 100 USD purchase:  "<<discount<<"%"<<endl;
    double a;
    again:
    cout<<"Do you want to update discount? (y/n): ";
    cin>>Choice;
    switch(Choice)
    {
        case 'Y': case 'y':
            cout<<"Enter new discount value in percentage: ";
            cin>>discount;
            break;
        case 'n': case 'N':
            break;
        default:
            cout<<"Invalid choice";            
    }
    cout<<"\n\n\n";
    return ;
}



int showAdminFunctions()
{
        cout<<"\n\n";
        cout<<"===================================="<<endl;
        cout<<"              Admin"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Select from the following:";
        cout<<"\n1. Update games and prices";
        cout<<"\n2. Delete games and prices";
        cout<<"\n3. Views Games";
        cout<<"\n4. Back to Main Menu ";
        cout<<"\n5. Update discount \n";
        cout<<"You chose: ";
        cin>>function_choice;
        cout<<"\n\n\n";
        return function_choice;
        
}

int showClientFunctions()
{
        cout<<"\n\n";
        cout<<"===================================="<<endl;
        cout<<"              Client"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Select from the following:";
        cout<<"\n1. View games";
        cout<<"\n2. Select games";
        cout<<"\n3. Checkout";
        cout<<"\n4. Back to Main Menu\n";
        cout<<"You chose: ";
        cin>>function_choice;
        cout<<"\n\n\n";
        return function_choice;
}




void addGames()
{
    //Checking for max limit to add games

    if(game_counter<50 && game_counter>=0)
    {
        if(game_deleted==false)
        {
            cout<<"Enter name of game:  ";
            cin>>game[game_counter].NAME;
            cout<<"Enter price of game in USD:";
            cin>>game[game_counter].PRICE;
            game_counter++;
            return;

        }

        else
        {
            cout<<"Enter name of game:  ";
            cin>>game[delete_counter].NAME;
            cout<<"Enter price of game in USD:";
            cin>>game[delete_counter].PRICE;
            game_deleted=false;
            delete_counter=game_counter;
            return;
        }

    }
   
    else
    {
       cout<<"Can't add more games. Storage full!\n"; 
    }
    
    cout<<"\n\n\n";
    return;
}










void viewGames()
{
    cout<<"============================================="<<endl;
    cout<<left<<setw(15)<<"Serial No."<<setw(25)<<"NAME"<<setw(5)<<"PRICE"<<endl;
    cout<<"============================================="<<endl;
    for(int i=0; i<=game_counter;i++)
    {
        
        cout<<left<<setw(15)<<i<<setw(25)<<game[i].NAME<<setw(5)<<game[i].PRICE<<endl;
        
        cout<<"_____________________________________________"<<endl;
    }
    cout<<"\n\n\n";
    return;
}



void deleteGames()
{
    

   
    
if(game_counter>=0 && game_counter<50)
{
        char del_index;
    cout<<"Do you want to view game indexes? (y/n): "<<endl;
    cin>>del_index;
    switch (del_index)
    {
    case 'Y': case 'y':
        viewGames();
        break;
    case 'n': case 'N':
        break;
    default:
        cout<<"Invalid choice! \n";
    }
    char choice;

    cout<<"Select the index of game you want to delete:";
    cin>>delete_counter;
    game[delete_counter].NAME="";
    game[delete_counter].PRICE=0.0;
    game_deleted=true;
    cout<<"\n\n\n";
    return;
}

 else
    {
        cout<<"There is no game to delete. Add a game first!!!"<<endl;
        game_deleted=false;
        return;
    }
}


void addToCart()
{
    int Cart;
    char Choice;
    viewGames();
    again:
    cout<<"Select a game by entering its index:";
    cin>>Cart;

    cart[cart_counter].name = game[Cart].NAME;
    cart[cart_counter].price = game[Cart].PRICE;
    cart_counter++;
    Again:
    cout<<"Do you want to add more games? (y/n): ";
    cin>>Choice;
    switch(Choice)
    {
        case 'y': case 'Y':
            goto again;
        case 'n': case 'N':
            return ;
        default:
            cout<<"Invalid choice!"<<endl;
    }
    cout<<"\n\n\n";
    return ;
}

void checkout()
{   
    
    cout<<"===================================="<<endl;
        cout<<"              Receipt"<<endl;
        cout<<"===================================="<<endl;
    cout<<"============================================="<<endl;
    cout<<left<<setw(15)<<"Serial No."<<setw(25)<<"NAME"<<setw(5)<<"PRICE"<<endl;
    cout<<"============================================="<<endl;
    for(int i=0; i<=cart_counter;i++)
    {
        
        cout<<left<<setw(15)<<i+1<<setw(25)<<cart[i].name<<setw(5)<<cart[i].price<<endl;
        
        cout<<"_____________________________________________"<<endl;
        sum=sum+cart[i].price;
    }

      
        cout<<left<<setw(15)<<"Total"<<setw(25)<<setw(5)<< sum <<endl;
        if (sum>100.0)
        {
            
            cout<<left<<setw(15)<<"Discount"<<setw(25)<<setw(5)<< discount<<"%" <<endl; 
            cout<<left<<setw(15)<<"Final Price"<<setw(25)<<setw(5)<< sum-(sum*(discount/100)) <<endl; 
            
        }
cout<<"\n\n\n";
    return;

}











int main()
{   
    int account,pass_manager,tries=0,choice,i,id,functions;
    string password;
    pass_manager=0;
        
        
    
   //Login menu
   do{
    main_menu:
    cout<<"===================================="<<endl;
         cout<<"Choose an option:"<<endl<<"1.Admin    2.Customer   3.Exit"<<endl;
        cout<<"===================================="<<endl;
   
    cin>>account;
   }while(account>3);


   
    if(account==1 || account==2)
    {
do{
    {cout<<"Enter password:";
    cin>>password;
    switch(account)
    {
        case 1:
            if(password=="admin123")
               { cout<<"Admin have successfully logged in."<<endl;
                pass_manager=1;
                break;}
            
            else
               { cout<<"Wrong password!"<<endl;
                pass_manager=0;}
            break;

        case 2:
            if(password=="customer123")
                {cout<<"Customer have succesfully logged in"<<endl;
                pass_manager=2;
                break;}
            else
               { cout<<"Wrong password!"<<endl;
                pass_manager=0;}
            break;
        case 3:
                break;
        default:
        	cout<<"Invalid choice";
    }
    tries++;
    }
    
    
}while(pass_manager==0 && tries!=3);
}
    if(account==3)
    {    cout<<"Program Exited!";
            exit(0);
    }

//Admin and Client functions
switch(pass_manager)
{
        case 1:
        admin:
        functions =showAdminFunctions();   //User-defined
        
        switch(functions)
        {
            case 1:
                addGames();
                goto admin;
                break;
            case 2:
                deleteGames();
                goto admin;
                break;
            case 3:
                viewGames();
                goto admin;
                break;
            case 4:
                goto main_menu;
                break;
            case 5:
                updateDiscount();
                goto admin;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
                goto admin;
        }
        
        break;

        case 2:
    
        client:
        functions=showClientFunctions();
        switch(functions)
        {
            case 1:
                viewGames();
                goto client;
                break;
            case 2:
                addToCart();
                goto client;
                break;
            case 3:
                char c;
                checkout();
                again:
                cout<<"Do you want to pay by card? (y/n): ";
                cin>>c;
                switch(c)
                {
                    case 'y': case 'Y':
                        cout<<"Paid "<<sum-(sum*(discount/100))<<" by card. Thank you for shopping from us."<<endl;
                    exit(0);
                    case 'n': case 'N':
                    cout<<"Paid "<<sum-(sum*(discount/100))<<" by cash. Thank you for shopping from us."<<endl;
                    exit(0);
                    default:
                    cout<<"Invalid choice"<<endl;                   

                }
                break;
            case 4:
                goto main_menu;
                break;
            default:
                cout<<"Invalid choice!";
                goto client;
        }
    
    
    
        break;

        default:
            cout<<"Invalid Choice!";
        
}

    return 0;
}