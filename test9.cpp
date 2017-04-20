typedef struct sFileList {
    int size;
    String *fileName;
    String *filePath;
    String *fileExt;
} fileList;
 
void arrStr_Create( String *arr, int size ) {
    // W domyœle zawsze bêdzie 0
    arr = new String[size];
}
 
void arrStr_Add( String *arr, int size, String var ) {
    String *newArr = new String[ size+1 ];
    for ( int i=0; i<size; i++ ) {
        newArr[i] = arr[i];
    }
    newArr[size] = var;
 
    arr = new String[ size+1 ];
    for ( int i=0; i<=size; i++ ) {
        arr[i] = newArr[i];
    }    
}
 
String arrStr_Get( String *arr, int size, int index ) {
    if ( index < size || index >= size ) { return ""; }
    return arr[index];
}
 
void arrStr_Delete( String *arr, int size, int index ) {
    String *newArr = new String[ size-1 ];
    int n = 0;
    for ( int i=0; i<size; i++ ) {
        if ( i != index ) {
            newArr[n] = arr[i];
            n++;
        }
    }
    newArr[size] = var;
 
    arr = new String[ size-1 ];
    for ( int i=0; i<=size; i++ ) {
        arr[i] = newArr[i];
    }
}  
 
void newFileList( fileList *FL ) {
        FL->size = 0;
        arrStr_Create( FL->fileName, FL->size );
        arrStr_Create( FL->filePath, FL->size );
        arrStr_Create( FL->fileExt, FL->size );
}
 
void addFileList( fileList *FL, String file ) {
    arrStr_Add( FL->fileName, FL->size, ExtractFileName( file ) );
    arrStr_Add( FL->filePath, FL->size, ExtractFilePath( file ) );
    arrStr_Add( FL->fileExt, FL->size, ExtractFileExt( file ) );
    FL->size++;
}
 
void removeFileList( fileList *FL, int index ) {
    arrStr_Delete( FL->fileName, FL->size, index );
    arrStr_Delete( FL->filePath, FL->size, index );
    arrStr_Delete( FL->fileExt, FL->size, index );
    FL->size--;
}