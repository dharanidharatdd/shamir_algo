#include "rapidjson/document.h" 
#include "rapidjson/filereadstream.h" 
#include <iostream> 

int main() 
{ 
	// Open the file for reading 
	FILE* fp = fopen("data.json", "r"); 

	// Use a FileReadStream to 
	// read the data from the file 
	char readBuffer[65536]; 
	rapidjson::FileReadStream is(fp, readBuffer, 
								sizeof(readBuffer)); 

	// Parse the JSON data 
	// using a Document object 
	rapidjson::Document d; 
	d.ParseStream(is); 

	// Close the file 
	fclose(fp); 

	// Access the data in the JSON document 
	std::cout << d["name"].GetString() << std::endl; 
	std::cout << d["age"].GetInt() << std::endl; 

	return 0; 
}
