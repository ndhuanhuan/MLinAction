void readNLines(const std:: string& fname, int n)
{
	ifstream infile(fname.c_str);
	if(!infile.is_open)
	{
		cout<<"Wrong"<<endl;
		return;
	}
	queue<string> lines;
	string line;
	while(getline(infile,line))
	{
		if(lines.size()>=n)
		{
			lines.pop();
		}
		lines.push(line);
	}
	infile.close();
	while(!lines.empty())
	{
		cout<<"line = "<<lines.front()<<endl;
		lines.pop();
	}
	
}
