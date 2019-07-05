#include <iostream>

#include "htmlGen.hpp"

using namespace std;

const string htmlGen::tagList[ HTML_TAG_COUNT ] =
{
	"html",
	"title",
	"body",
	"div",
	"h1",
	"h2",
	"img",
	"table",
	"th",
	"tr",
	"td",
	"style",
	"p"
};

htmlGen::htmlGen( )
{
	depth = 0;
}

void htmlGen::openTag( HTML_TAG tag, vector<string> properties, bool newLineAfter )
{
	writeTag( tag, true, false, properties, newLineAfter );
	depth++;
}
void htmlGen::closeTag( HTML_TAG tag, bool newLineAfter )
{
	depth--;
	writeTag( tag, false, false, {}, newLineAfter );
}
void htmlGen::writeTagWithValue( HTML_TAG tag, string value, std::vector<std::string> properties, bool autoClose, bool newLineAfter )
{
	writeTag( tag, true, autoClose, properties, false, true );
	if( !autoClose )
	{
		write( value, false, false );
		writeTag( tag, false, false, {}, true, false );
	}
	else if( newLineAfter )
	{
		data << endl;
	}
}
void htmlGen::write( string value, bool newLineAfter, bool writeDepthBefore )
{
	if( writeDepthBefore )
	{
		writeDepth( );
	}
	data << value;
	if( newLineAfter )
	{
		data << endl;
	}
}
void htmlGen::writeTag( HTML_TAG tag, bool open, bool autoClose, vector<string> properties, bool newLineAfter, bool writeDepthBefore )
{
	if( tag < HTML_TAG_COUNT )
	{
		if( writeDepthBefore )
		{
			writeDepth( );
		}
		data << "<";
		if( !open )
		{
			data << "/";
		}
		data << tagList[ tag ];
		for( auto &v : properties )
		{
			data << " " << v;
		}
		if( open && autoClose )
		{
			data << " /";
		}
		data << ">";
		if( newLineAfter )
		{
			data << endl;
		}
	}
}
void htmlGen::writeDepth( )
{
	for( int i = 0; i < depth; i++ )
	{
		data << "\t";
	}
}

void htmlGen::printData( )
{
	cout << data.str( );
}

// GCOV_EXCL_START
// GCOVR_EXCL_START
void htmlGen::writeFile( string fileName )
{
	ofstream fileOut ( fileName );
	fileOut << data.str( );
	fileOut.close( );
}
// GCOVR_EXCL_STOP
// GCOV_EXCL_STOP