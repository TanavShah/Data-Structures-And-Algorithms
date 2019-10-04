  } 
        } while (ptr != mini && ptr->right != NULL); 
        cout << endl 
             << "The heap has " << no_of_nodes << " nodes" << endl 
             << endl; 
    } 
} 
  
// Driver code 
int main() 
{ 
    // We will create a heap and insert 3 nodes into it 
    cout << "Creating an initial heap" << endl; 
    insertion(5); 
    insertion(2); 
    insertion(8); 
  
    // Now we will display the root list of the heap 
    display(); 
  
    // Now we will extract the minimum value node from the heap 
    cout << "Extracting min" << endl; 
    Extract_min(); 
    display(); 
  
    // Now we will decrease the value of node '8' to '7' 
    cout << "Decrease value of 8 to 7" << endl; 
    Find(mini, 8, 7); 
    display(); 
  
    // Now we will delete the node '7' 
    cout << "Delete the node 7" << endl; 
    Deletion(7); 
    display(); 
  
    return 0; 
} 
