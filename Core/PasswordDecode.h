std::string PWDDecode(char Value[50])
{
	std::string m;

	for (int i = 0; Value[i] != '\0'; i+=2)
	{
		std::string x,y,z="";
		x = x + Value[i] + Value[i+1];
		
		if (x.substr(0,2) == "2C") y = y+"0";
		if (x.substr(0,2) == "95") y = y+"!";
		if (x.substr(0,2) == "88") y = y+'"';
		if (x.substr(0,2) == "9D") y = y+"#";
		if (x.substr(0,2) == "4C") y = y+"$";
		if (x.substr(0,2) == "F2") y = y+"%";
		if (x.substr(0,2) == "3E") y = y+"&";
		if (x.substr(0,2) == "C0") y = y+"(";
		if (x.substr(0,2) == "7F") y = y+")";
		if (x.substr(0,2) == "18") y = y+"*";
		if (x.substr(0,2) == "70") y = y+"+";
		if (x.substr(0,2) == "6A") y = y+",";
		if (x.substr(0,2) == "E2") y = y+"-";
		if (x.substr(0,2) == "EC") y = y+".";
		if (x.substr(0,2) == "77") y = y+"/";
		if (x.substr(0,2) == "3A") y = y+"1";
		if (x.substr(0,2) == "4A") y = y+"2";
		if (x.substr(0,2) == "91") y = y+"3";
		if (x.substr(0,2) == "5D") y = y+"4";
		if (x.substr(0,2) == "7A") y = y+"5";
		if (x.substr(0,2) == "29") y = y+"6";
		if (x.substr(0,2) == "BC") y = y+"7";
		if (x.substr(0,2) == "6E") y = y+"8";
		if (x.substr(0,2) == "D4") y = y+"9";
		if (x.substr(0,2) == "40") y = y+":";
		if (x.substr(0,2) == "17") y = y+";";
		if (x.substr(0,2) == "2E") y = y+"<";
		if (x.substr(0,2) == "CB") y = y+"=";
		if (x.substr(0,2) == "72") y = y+">";
		if (x.substr(0,2) == "9C") y = y+"?";
		if (x.substr(0,2) == "A1") y = y+"@";
		if (x.substr(0,2) == "FF") y = y+"A";
		if (x.substr(0,2) == "F3") y = y+"B";
		if (x.substr(0,2) == "F8") y = y+"C";
		if (x.substr(0,2) == "9B") y = y+"D";
		if (x.substr(0,2) == "50") y = y+"E";
		if (x.substr(0,2) == "51") y = y+"F";
		if (x.substr(0,2) == "6D") y = y+"G";
		if (x.substr(0,2) == "E9") y = y+"H";
		if (x.substr(0,2) == "9A") y = y+"I";
		if (x.substr(0,2) == "B8") y = y+"J";
		if (x.substr(0,2) == "84") y = y+"K";
		if (x.substr(0,2) == "A8") y = y+"L";
		if (x.substr(0,2) == "14") y = y+"M";
		if (x.substr(0,2) == "38") y = y+"N";
		if (x.substr(0,2) == "CE") y = y+"0";
		if (x.substr(0,2) == "92") y = y+"P";
		if (x.substr(0,2) == "5C") y = y+"Q";
		if (x.substr(0,2) == "F5") y = y+"R";
		if (x.substr(0,2) == "EE") y = y+"S";
		if (x.substr(0,2) == "B3") y = y+"T";
		if (x.substr(0,2) == "89") y = y+"U";
		if (x.substr(0,2) == "7B") y = y+"V";
		if (x.substr(0,2) == "A2") y = y+"W";
		if (x.substr(0,2) == "AD") y = y+"X";
		if (x.substr(0,2) == "71") y = y+"Y";
		if (x.substr(0,2) == "E3") y = y+"Z";
		if (x.substr(0,2) == "D5") y = y+"[";
		if (x.substr(0,2) == "BF") y = y+"\\";
		if (x.substr(0,2) == "53") y = y+"]";
		if (x.substr(0,2) == "28") y = y+"^";
		if (x.substr(0,2) == "44") y = y+"_";
		if (x.substr(0,2) == "33") y = y+"`";
		if (x.substr(0,2) == "48") y = y+"a";
		if (x.substr(0,2) == "DB") y = y+"b";
		if (x.substr(0,2) == "FC") y = y+"c";
		if (x.substr(0,2) == "09") y = y+"d";
		if (x.substr(0,2) == "1F") y = y+"e";
		if (x.substr(0,2) == "94") y = y+"f";
		if (x.substr(0,2) == "12") y = y+"g";
		if (x.substr(0,2) == "73") y = y+"h";
		if (x.substr(0,2) == "37") y = y+"i";
		if (x.substr(0,2) == "82") y = y+"j";
		if (x.substr(0,2) == "81") y = y+"k";
		if (x.substr(0,2) == "39") y = y+"l";
		if (x.substr(0,2) == "C2") y = y+"m";
		if (x.substr(0,2) == "8D") y = y+"n";
		if (x.substr(0,2) == "7D") y = y+"o";
		if (x.substr(0,2) == "08") y = y+"p";
		if (x.substr(0,2) == "4F") y = y+"q";
		if (x.substr(0,2) == "B0") y = y+"r";
		if (x.substr(0,2) == "FE") y = y+"s";
		if (x.substr(0,2) == "79") y = y+"t";
		if (x.substr(0,2) == "0B") y = y+"u";
		if (x.substr(0,2) == "D6") y = y+"v";
		if (x.substr(0,2) == "23") y = y+"w";
		if (x.substr(0,2) == "7C") y = y+"x";
		if (x.substr(0,2) == "4B") y = y+"y";
		if (x.substr(0,2) == "8E") y = y+"z";
		if (x.substr(0,2) == "06") y = y+"{";
		if (x.substr(0,2) == "5A") y = y+"|";
		if (x.substr(0,2) == "CC") y = y+"}";
		if (x.substr(0,2) == "62") y = y+"~";

		m = m+y;
	}
	
	return m;
}