#include<iostream>
#include<iomanip>
using namespace std;





//Data
int counter=4,function_choice=0, serial=1,_delete , new_index,  cart_counter=0 ;
string name[50]={"Black Myth: Wukong","Monster Hunter Wilds","HELlDIVERS 2","GTA V","Rust"};
double price[50]={50,45,80,96,74};
char del_index;
string name_cart[50];
double price_cart[50],discount=5;
double sum=0.0;





void updateDiscount()
{
    char Choice;
    cout<<"Current discount offer on more than 100 USD purchase:  "<<discount/100<<"%"<<endl;
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
            goto again;
    }
    cout<<"\n\n\n";
    return ;
}



int showAdminFunctions()
{
        cout<<"===================================="<<endl;
        cout<<"              Admin"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Select from the following:";
        cout<<"\n1.Update games and prices";
        cout<<"\n2.Delete games and prices";
        cout<<"\n3.Views Games";
        cout<<"\n4.Back to Main Menu ";
        cout<<"\n5. Update discount";
        cin>>function_choice;
        cout<<"\n\n\n";
        return function_choice;
        
}

int showClientFunctions()
{
        cout<<"===================================="<<endl;
        cout<<"              Client"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Select from the following:";
        cout<<"\n 1.View games";
        cout<<"\n2.Select games";
        cout<<"\n3.Checkout";
        cout<<"\n4.Back to Main Menu";
        cin>>function_choice;
        cout<<"\n\n\n";
        return function_choice;
}




void addGames()
{
    add:
    if(counter==50)
    {
        cout<<"Cannot add more games!!!";
        return;
    }

    if(new_index==0){
    cout<<"Enter name of game:  ";
    cin>>name[counter];
    cout<<"Enter price of game in USD:";
    cin>>price[counter];
    }
    else if(new_index==1){
    cout<<"Enter name of game:  ";
    cin>>name[_delete];
    cout<<"Enter price of game in USD:";
    cin>>price[_delete];
    }
    counter++;
    char choice;
    again:
    cout<<"Do you want to add another game?(y/n): ";
    cin>>choice;
    switch(choice)
    {
        case 'Y': case 'y':
            goto add;
            break;
        case 'N': case 'n':
            return;
            break;
        default:
            goto again;
    }
    cout<<"\n\n\n";
    return;
}










void viewGames()
{
    cout<<"============================================="<<endl;
    cout<<left<<setw(15)<<"Serial No."<<setw(25)<<"NAME"<<setw(5)<<"PRICE"<<endl;
    cout<<"============================================="<<endl;
    for(int i=0; i<=counter;i++)
    {
        
        cout<<left<<setw(15)<<i<<setw(25)<<name[i]<<setw(5)<<price[i]<<endl;
        
        cout<<"_____________________________________________"<<endl;
    }
    cout<<"\n\n\n";
    return;
}



void deleteGames()
{
    if(counter<=0)
    {
        cout<<"There is no game to delete. Add a game first!!!"<<endl;
        new_index=0;
        return;
    }
    again:
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
        goto again;
    }
    char choice;

    cout<<"Select the index of game you want to delete:";
    cin>>_delete;
    _delete;
    name[_delete]="";
    price[_delete]=0.0;
    new_index=1;
    cout<<"\n\n\n";
    return;
}



void addToCart()
{
    int cart;
    char Choice;
    viewGames();
    again:
    cout<<"Select a game by entering its index:";
    cin>>cart;
    name_cart[cart_counter]=name[cart];
    price_cart[cart_counter]=price[cart];
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
            goto Again;
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
        
        cout<<left<<setw(15)<<i+1<<setw(25)<<name_cart[i]<<setw(5)<<price_cart[i]<<endl;
        
        cout<<"_____________________________________________"<<endl;
        sum=sum+price_cart[i];
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
        do{
        admin:
        functions =showAdminFunctions();   //User-defined
        
        switch(functions)
        {
            case 1:
                addGames();
                break;
            case 2:
                deleteGames();
                break;
            case 3:
                viewGames();
                break;
            case 4:
                goto main_menu;
                break;
            case 5:
                updateDiscount();
            default:
                cout<<"Invalid choice!";
                goto admin;
        }
    }while(functions!=4);
        break;

    case 2:
    do{
        client:
        functions=showClientFunctions();
        switch(functions)
        {
            case 1:
                viewGames();
                break;
            case 2:
                addToCart();
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
                        goto again;

                }
                break;
            case 4:
                goto main_menu;
                break;
            default:
                cout<<"Invalid choice!";
                goto client;
        }
    }while (functions!=4);
    
    
        break;
        
}

    return 0;
}