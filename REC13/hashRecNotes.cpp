/*
HASHING
- technique used for storing, retrieving and deleting information as fast as possible,
fastest being O(1)

//Quadratic Probing
    index = hash(record.key);
    i=1;
    while(hash_table[index] is occupied){
        index = (index + i^2)% hash_table_size;
        i+=1;

    }


//insert and search in a hash table
   
*/