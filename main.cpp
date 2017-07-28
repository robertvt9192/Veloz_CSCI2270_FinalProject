#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Graph.cpp"

using namespace std;


int main()
{
    BSTree<string> porTree;
    porTree.inser("Manteigaria", "5/5", "$");
    porTree.inser("Cervejaria Ramiro", "4/5", "$$$");
    porTree.inser("Time Out Market", "4/5", "$$");
    porTree.inser("Floresta do Salitre", "3/5", "$$");


    BSTree<string> spaTree;
    spaTree.inser("El Sur", "4.5/5", "$");
    spaTree.inser("La Tragantua", "4/5", "$$");
    spaTree.inser("Takos al Pastor", "4.5/5", "$");
    spaTree.inser("Toma Cafe", "3/5", "$");

    BSTree<string> fraTree;
    fraTree.inser("L'Estrapade", "5/5", "$$$");
    fraTree.inser("La Cordonnerie", "4.5/5", "$$$");
    fraTree.inser("L'Avant Comptoir", "4.5/5", "$$");
    fraTree.inser("Comptoir de la Gastronomie", "4/5", "$$");
    fraTree.inser("Le Bistrot des Augustins", "4/5", "$");

    BSTree<string> itaTree;
    itaTree.inser("Pane e Salame", "5/5", "$$$");
    itaTree.inser("La Prosciutteria", "4.5/5", "$$$");
    itaTree.inser("Pane & Vino", "4.5/5", "$$");
    itaTree.inser("Pizza Pizza", "4/5", "$$");
    itaTree.inser("Osteria del Cavaliere", "4/5", "$");

    BSTree<string> swiTree;
    swiTree.inser("The Bite", "5/5", "$$$");
    swiTree.inser("Isebahnli", "4.5/5", "$$$");
    swiTree.inser("Hiltl", "4.5/5", "$$");
    swiTree.inser("Kafi Dihei", "4/5", "$$");
    swiTree.inser("Cafe Noir", "4/5", "$");

    BSTree<string> gerTree;
    gerTree.inser("Lorenz Adlon Esszimmer", "5/5", "$$$");
    gerTree.inser("Rausch Schokoladenhaus", "4.5/5", "$$$");
    gerTree.inser("Weingalerie und Cafe NO!", "4.5/5", "$$");
    gerTree.inser("Figl", "4/5", "$$");
    gerTree.inser("Imbiss 204", "4/5", "$");

    BSTree<string> belTree;
    belTree.inser("Mer du Nord", "5/5", "$$$");
    belTree.inser("My Little Cup", "4.5/5", "$$$");
    belTree.inser("Winehouse Osteria", "4.5/5", "$$");
    belTree.inser("Peck 47", "4/5", "$$");
    belTree.inser("Boulangerie Charli", "4/5", "$");

    Graph<string> g;
    g.addVertex("Portugal");
    g.addVertex("Spain");
    g.addVertex("France");
    g.addVertex("Italy");
    g.addVertex("Switzerland");
    g.addVertex("Germany");
    g.addVertex("Belgium");

    vertex<string>* port = g.searchG("Portugal");
    vertex<string>* spai = g.searchG("Spain");
    vertex<string>* fran = g.searchG("France");
    vertex<string>* ital = g.searchG("Italy");
    vertex<string>* swit = g.searchG("Switzerland");
    vertex<string>* germa = g.searchG("Germany");
    vertex<string>* belg = g.searchG("Belgium");

    port->restaurants = porTree.root;
    spai->restaurants = spaTree.root;
    fran->restaurants = fraTree.root;
    ital->restaurants = itaTree.root;
    swit->restaurants = swiTree.root;
    germa->restaurants = gerTree.root;

    //Portugal
    g.addEdge("Portugal","Spain",297);


    //Spain
    g.addEdge("Spain","Portugal",297);
    g.addEdge("Spain","France",623);

    //France
    g.addEdge("France","Spain",623);
    g.addEdge("France","Italy",808);
    g.addEdge("France","Belgium",409);
    g.addEdge("France","Germany",645);
    g.addEdge("France","Switzerland",415);

    //Belgium
    g.addEdge("Belgium","Germany",335);
    g.addEdge("Belgium","France",409);

    //Italy
    g.addEdge("Italy","France",808);
    g.addEdge("Italy","Switzerland",520);

    //Switzerland
    g.addEdge("Switzerland","France",415);
    g.addEdge("Switzerland","Italy",520);
    g.addEdge("Switzerland","Germany",411);

    //Germany
    g.addEdge("Germany","France",645);
    g.addEdge("Germany","Switzerland",411);
    g.addEdge("Germany","Belgium",335);



int choice;

    do{

        cout << "HELLO"<<endl<<"I am the touristnator 9999"<< endl;
        cout<< "HOW CAN I HELP YOU?" << endl;
        cout << "======Main Menu======"<<endl;
        cout << "1. Find Shortest Route" << endl;
        cout << "2. Restaurants" << endl;
        cout << "3. Adjacent" << endl;
        cout << "4. Quit" << endl;


        cin >> choice;


        switch(choice){

        case 1: {
            string s1,s2;
            int star;

            cout<< "Please enter starting location"<<endl;
            cout << "1. Portugal" << endl;
            cout << "2. Spain" << endl;
            cout << "3. France" << endl;
            cout << "4. Belgium" << endl;
            cout << "5. Germany" << endl;
            cout << "6. Switzerland" << endl;
            cout << "7. Italy" << endl;

            cin>>star;

            switch (star){
            case 1:{
                s1 = "Portugal";
                break;
            }
             case 2:{
                s1 = "Spain";
                break;
            }
             case 3:{
                s1 = "France";
                break;
            }
             case 4:{
                s1 = "Belgium";
                break;
            }
             case 5:{
                s1 = "Germany";
                break;
            }
             case 6:{
                s1 = "Switzerland";
                break;
            }
             case 7:{
                s1 = "Italy";
                break;
            }
            }

            int dest;

            cout<< "Please enter destination"<<endl;
            cout << "1. Portugal" << endl;
            cout << "2. Spain" << endl;
            cout << "3. France" << endl;
            cout << "4. Belgium" << endl;
            cout << "5. Germany" << endl;
            cout << "6. Switzerland" << endl;
            cout << "7. Italy" << endl;

            cin>>dest;

            switch (dest){
            case 1:{
                s2 = "Portugal";
                break;
            }
             case 2:{
                s2 = "Spain";
                break;
            }
             case 3:{
                s2 = "France";
                break;
            }
             case 4:{
                s2 = "Belgium";
                break;
            }
             case 5:{
                s2 = "Germany";
                break;
            }
             case 6:{
                s2 = "Switzerland";
                break;
            }
             case 7:{
                s2 = "Italy";
                break;
            }
            }


            vertex<string>* fast = g.Dijkstra(s1,s2);
            cout<< "The shortest path is " << fast->distance<< " miles long." << endl;
            break;
        }
        case 2: {
            string s2;
            int country;

            cout<< "Please choose:"<<endl;
            cout << "1. Portugal" << endl;
            cout << "2. Spain" << endl;
            cout << "3. France" << endl;
            cout << "4. Belgium" << endl;
            cout << "5. Germany" << endl;
            cout << "6. Switzerland" << endl;
            cout << "7. Italy" << endl;

            cin>>country;

            switch (country){
            case 1:{
                s2 = "Portugal";
                break;
            }
             case 2:{
                s2 = "Spain";
                break;
            }
             case 3:{
                s2 = "France";
                break;
            }
             case 4:{
                s2 = "Belgium";
                break;
            }
             case 5:{
                s2 = "Germany";
                break;
            }
             case 6:{
                s2 = "Switzerland";
                break;
            }
             case 7:{
                s2 = "Italy";
                break;
            }
            }
            vertex<string>* food = g.searchG(s2);
            cout<< endl<<"Here is a list of the finest restaurants in " << s2<<endl<<endl;
            g.restaurants(food->restaurants);
            cout << endl;
            break;
        }
        case 3: {
            string s1,s2;
            int star;

            cout<< "Please enter first location"<<endl;
            cout << "1. Portugal" << endl;
            cout << "2. Spain" << endl;
            cout << "3. France" << endl;
            cout << "4. Belgium" << endl;
            cout << "5. Germany" << endl;
            cout << "6. Switzerland" << endl;
            cout << "7. Italy" << endl;

            cin>>star;

            switch (star){
            case 1:{
                s1 = "Portugal";
                break;
            }
             case 2:{
                s1 = "Spain";
                break;
            }
             case 3:{
                s1 = "France";
                break;
            }
             case 4:{
                s1 = "Belgium";
                break;
            }
             case 5:{
                s1 = "Germany";
                break;
            }
             case 6:{
                s1 = "Switzerland";
                break;
            }
             case 7:{
                s1 = "Italy";
                break;
            }
            }

            int dest;

            cout<< "Please enter second location"<<endl;
            cout << "1. Portugal" << endl;
            cout << "2. Spain" << endl;
            cout << "3. France" << endl;
            cout << "4. Belgium" << endl;
            cout << "5. Germany" << endl;
            cout << "6. Switzerland" << endl;
            cout << "7. Italy" << endl;

            cin>>dest;

            switch (dest){
            case 1:{
                s2 = "Portugal";
                break;
            }
             case 2:{
                s2 = "Spain";
                break;
            }
             case 3:{
                s2 = "France";
                break;
            }
             case 4:{
                s2 = "Belgium";
                break;
            }
             case 5:{
                s2 = "Germany";
                break;
            }
             case 6:{
                s2 = "Switzerland";
                break;
            }
             case 7:{
                s2 = "Italy";
                break;
            }
            }
            cout<<endl<<endl;
            if(!g.adjacent(s1,s2)){
                cout<< s1 << " and " << s2 << " are not adjacent." << endl;
            }
            else {
                cout << s1 << " and " << s2 << " are adjacent."<< endl;
            }
            cout << endl <<endl;
            break;
        }

    }
    }while(choice != 4);
    g.displayEdges();



    return 0;
}
