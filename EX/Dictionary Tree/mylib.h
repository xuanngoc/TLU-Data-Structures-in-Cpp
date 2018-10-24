int Menu(){
	cout<<"---------- Dictionary  --------\n";
	cout<<"1. Them tu\n";
	cout<<"2. Tra tu\n";
	cout<<"0. Other\n";
	int c;
	cout<<"\nChon chuc nang: ";
	cin >> c;
	return c;
}

const char* ToUpper(char* word)
{
	int len = strlen(word);
	for(int i=0; i< len; i++)
	{
		if(word[i] <='z' && word[i] >= 'a')
			word[i] -= 32;
	}
	return word;
}