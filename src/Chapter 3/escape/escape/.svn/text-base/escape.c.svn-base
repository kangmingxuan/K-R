       void escape(char s[], char t[])
{
	int i, j;
	for(i = 0, j = 0; (s[j] = t[i]) != '\0'; ++i, ++j)
		switch (s[j]){
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				break;
			default:
				break;
		}
}

void rescape(char s[], char t[])
{
	int i, j;

	for(i = 0, j = 0; (s[j] = t[i] ) != '\0'; ++i, ++j)
		if (t[i] == '\\')
			switch (t[++i]){
				case 'n':
					s[j] = '\n';
					break;
				case 't':
					s[j] = '\t';
					break;
				default:
					--i;
					break;
			}
}