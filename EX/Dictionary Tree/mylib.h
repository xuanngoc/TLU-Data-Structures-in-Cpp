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