#include<bits/stdc++.h>
using namespace std;
class BloodBank;
enum group{O,A,B,AB};
enum Rh{positive,negative};
#define maximum 10000

class Bottle{
public:
    Bottle(){}
    void virtual put(){}
    int virtual get(int){}
    int virtual getAvailable(){}
};

class Blood{
    Bottle *bottle[maximum];
    int stock;
public:
    void virtual add();
    void virtual Remove(int c);
    int virtual available();
    Blood(){stock=0;}
};
void Blood::add(){
    bottle[stock]=new Bottle();
    stock++;
}
void Blood::Remove(int c){
    for(int i=0;i<c;i++){
        delete bottle[stock];
        bottle[stock]=NULL;
        stock--;
    }
    if(stock<0){
        stock=0;
    }
}
int Blood::available(){
    return stock;
}

class Oplus:public Blood{}oplus;
class Ominus:public Blood{}ominus;
class Aplus:public Blood{}aplus;
class Aminus:public Blood{}aminus;
class Bplus:public Blood{}bplus;
class Bminus:public Blood{}bminus;
class ABplus:public Blood{}abplus;
class ABminus:public Blood{}abminus;


class OPBottle:public Bottle{
public:
    OPBottle(){Bottle();}
    int virtual get(int);
    void virtual put();
    int virtual getAvailable();
}opbottle;
void OPBottle::put(){
    oplus.add();
}
int OPBottle::get(int no){
    int c,qty;
    c=oplus.available();
    oplus.Remove(qty=min(c,no));
    return c;
}
int OPBottle::getAvailable(){
    return oplus.available();
}

class ONBottle:public Bottle{
public:
    ONBottle(){Bottle();}
    int virtual get(int);
    void virtual put();
    int virtual getAvailable();
}onbottle;
void ONBottle::put(){
    ominus.add();
}
int ONBottle::get(int no){
    int c,qty;
    c=ominus.available();
    ominus.Remove(qty=min(c,no));
    return c;
}
int ONBottle::getAvailable(){
    return ominus.available();
}

class APBottle:public Bottle{
public:
    APBottle(){Bottle();}
    int virtual get(int);
    void virtual put();
    int virtual getAvailable();
}apbottle;
void APBottle::put(){
    aplus.add();
}
int APBottle::get(int no){
    int c,qty;
    c=aplus.available();
    aplus.Remove(qty=min(c,no));
    return c;
}
int APBottle::getAvailable(){
    return aplus.available();
}

class ANBottle:public Bottle{
public:
    ANBottle(){Bottle();}
    int virtual get(int);
    void virtual put();
    int virtual getAvailable();
}anbottle;
void ANBottle::put(){
    aminus.add();
}
int ANBottle::get(int no){
    int c,qty;
    c=aminus.available();
    aminus.Remove(qty=min(c,no));
    return c;
}
int ANBottle::getAvailable(){
    return aminus.available();
}

class BPBottle:public Bottle{
public:
    BPBottle(){Bottle();}
    int virtual get(int);
    void virtual put();
    int virtual getAvailable();
}bpbottle;
void BPBottle::put(){
    bplus.add();
}
int BPBottle::get(int no){
    int c,qty;
    c=bplus.available();
    bplus.Remove(qty=min(c,no));
    return c;
}
int BPBottle::getAvailable(){
    return bplus.available();
}

class BNBottle:public Bottle{
public:
    BNBottle(){Bottle();}
    int virtual get(int);
    void virtual put();
    int virtual getAvailable();
}bnbottle;
void BNBottle::put(){
    bminus.add();
}
int BNBottle::get(int no){
    int c,qty;
    c=bminus.available();
    bminus.Remove(qty=min(c,no));
    return c;
}
int BNBottle::getAvailable(){
    return bminus.available();
}

class ABPBottle:public Bottle{
public:
    ABPBottle(){Bottle();}
    int virtual get(int);
    void virtual put();
    int virtual getAvailable();
}abpbottle;
void ABPBottle::put(){
    abplus.add();
}
int ABPBottle::get(int no){
    int c,qty;
    c=abplus.available();
    abplus.Remove(qty=min(c,no));
    return c;
}
int ABPBottle::getAvailable(){
    return abplus.available();
}

class ABNBottle:public Bottle{
public:
    ABNBottle(){Bottle();}
    int virtual get(int);
    void virtual put();
    int virtual getAvailable();
}abnbottle;
void ABNBottle::put(){
    abminus.add();
}
int ABNBottle::get(int no){
    int c,qty;
    c=abminus.available();
    abminus.Remove(qty=min(c,no));
    return c;
}
int ABNBottle::getAvailable(){
    return abminus.available();
}

class Menu
{
public:
    int get_option(char* text);
}menu;
int Menu::get_option(char* text)
{
    int a;
    cout<<text;
    cout<<"\nEnter your choice : ";
    cin>>a;
    return a;
}

class Input
{
protected:
    char* text;
    int choice;
public:
    Input(){};
    int get_group();
    int get_rh();
    int get_qty();
}input;
int Input::get_group()
{
    int choice;
    text="\nThe different blood groups are \n\n\t0\tO\n\t1\tA\n\t2\tB\n\t3\tAB\n";
    choice=menu.get_option(text);
    return choice;
}
int Input::get_rh()
{
    int choice;
    text="\nThe different Rh factors are\n\n\t0\t+\n\t1\t-\n";
    choice=menu.get_option(text);
    return choice;
}
int Input::get_qty()
{
    int num;
    text="\nEnter the number of bottles : ";
    cout<<text;
    cin>>num;
    return num;
}

class Output
{
public:
    void display(int,int);
}output;
void Output::display(int c,int num)
{
    cout<<"\nYou had requested for "<<num<<" bottle(s)";
    if(c==0)
    {
        cout<<"\nSorry! No bottle is available!";
    }
    else
    {
        if(c<num)
        {
            if(c==1)
            {
                cout<<"\nOnly 1 bottle has been delivered.";
            }
            else
            {
                cout<<"\nOnly "<<c<<" bottles have been delivered.";
            }
        }
        else
        {
            cout<<"\nAll bottles are delivered";
        }
    }
}
int findAge(int birth_date,int birth_month, int birth_year)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int month[] = { 31, 28, 31, 30, 31, 30, 31,
                          31, 30, 31, 30, 31 };
    int current_date=ltm->tm_mday;
    int current_month=(1 + ltm->tm_mon);
    int current_year=(1900+ltm->tm_year);
    if (birth_date > current_date) {
        current_date = current_date + month[birth_month - 1];
        current_month = current_month - 1;
    }
    if (birth_month > current_month) {
        current_year = current_year - 1;
        current_month = current_month + 12;
    }
    int calculated_date = current_date - birth_date;
    int calculated_month = current_month - birth_month;
    int calculated_year = current_year - birth_year;
    return calculated_year;
}
int findEligibility(int last_date,int last_month, int last_year)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int month[] = { 31, 28, 31, 30, 31, 30, 31,
                          31, 30, 31, 30, 31 };
    int current_date=ltm->tm_mday;
    int current_month=(1 + ltm->tm_mon);
    int current_year=(1900+ltm->tm_year);
    if (last_date > current_date) {
        current_date = current_date + month[last_month - 1];
        current_month = current_month - 1;
    }
    if (last_month > current_month) {
        current_year = current_year - 1;
        current_month = current_month + 12;
    }
    int calculated_date = current_date - last_date;
    int calculated_month = current_month - last_month;
    int calculated_year = current_year - last_year;
    if(calculated_year==0&& calculated_month<=2) return calculated_month;
    else return -1;
}

class Form{
    friend class BloodBank;
protected:
    int gr,rh;
public:
    Form(){}
    virtual void fill_form()=0;
};
class Request_form:public Form{
    friend class BloodBank;
    int qty;
public:
    void fill_form();
}request_form;
void Request_form::fill_form(){
    gr=input.get_group();
    rh=input.get_rh();
    qty=input.get_qty();
}

class Donate_form:public Form{
    friend class BloodBank;
public:
    void fill_form();
}donate_form;
void Donate_form::fill_form(){
    int d1,m1,y1;
    cout<<"Enter your date of birth in DD MM YYYY format: ";
    cin>>d1>>m1>>y1;
    if(findAge(d1,m1,y1)<18){
            cout<<"SORRY! You are currently under age."<<endl;
            gr=4;
            rh=0;
            return;
    }
    cout<<"Have you donated blood before?\n\t0.Yes\n\t1.No"<<endl;
    int ans;
    cin>>ans;
    if(ans==0){
        cout<<"\nPlease enter date when donation was last made in DD MM YYYY format: ";
        int d2,m2,y2;
        cin>>d2>>m2>>y2;
        int duration=findEligibility(d2,m2,y2);
        if(duration>=0&&duration<=2){
            cout<<"It's been "<<duration<<" months since your last donation. You can donate only 3 months after last donation.\nSo you cannot donate today. Please visit later."<<endl;
            gr=4;
            rh=0;
            return;
        }
        else{
            cout<<"You are eligible to donate blood."<<endl;
        }
    }
    gr=input.get_group();
    rh=input.get_rh();
    cout<<"THANKS FOR DONATING!"<<endl;
}

class BloodBank{
    Bottle * arr[5][2];
public:
    BloodBank();
    void accept(Donate_form);
    void request(Request_form);
}blood_bank;
BloodBank::BloodBank(){
    arr[0][0]=&opbottle;
    arr[0][1]=&onbottle;
    arr[1][0]=&apbottle;
    arr[1][1]=&anbottle;
    arr[2][0]=&bpbottle;
    arr[2][1]=&bnbottle;
    arr[3][0]=&abpbottle;
    arr[3][1]=&abnbottle;
}
void BloodBank::accept(Donate_form f){
    if(f.gr<=3){
    (*arr[f.gr][f.rh]).put();
    }
}
void BloodBank::request(Request_form f){
    int c;
    c=(*arr[f.gr][f.rh]).getAvailable();
    if(c>0){
        if(c<f.qty){
            (*arr[f.gr][f.rh]).get(c);
        }
        else{
            (*arr[f.gr][f.rh]).get(f.qty);
        }
    }
    output.display(c,f.qty);
}

class Transaction{
    char*  text;
public:
    int get_kind();
    void start();
}transaction;
int Transaction::get_kind(){
    text="\n\nWould you like to\n\n\t0\tDonate\n\t1\tBorrow\n\t2\tExit\n\n";
    int choice;
    choice=menu.get_option(text);
    return choice;
}
void Transaction::start(){
    int choice;
    choice=get_kind();
    while(choice!=2){
        if(choice==0){
            donate_form.fill_form();
            blood_bank.accept(donate_form);
        }
        else{
            request_form.fill_form();
            blood_bank.request(request_form);
        }
        choice=get_kind();
    }
}
class Camp{
    char *text;
public:
    void start();
    int get_kind();
}camp;
int Camp::get_kind(){
    text="\n\nWould you like to \n\n\t0\tDonate\n\t1\tExit\n\n";
    int choice;
    choice=menu.get_option(text);
    return choice;
}
void Camp::start(){
    int choice;
    choice=get_kind();
    while(choice!=1){
        donate_form.fill_form();
        blood_bank.accept(donate_form);
        choice=get_kind();
    }
}

int main(){
    system("color 4F");
    int opn;
    do{
    system("cls");
    cout<<"Choose appropriate option:\n\t0.\tBlood Transaction\n\t1.\tBlood Donation Camp\n\t2.\tExit\n";
    cin>>opn;
    switch(opn){
    case 0:
        transaction.start();
        break;
    case 1:
        camp.start();
        break;
    case 2:
        exit(0);
    }
    }while(opn!=2);
}
