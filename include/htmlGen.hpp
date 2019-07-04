#ifndef HTML_GEN_HPP__
#define HTML_GEN_HPP__

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

typedef enum
{
	HTML_TAG_HTML,
	HTML_TAG_TITLE,
	HTML_TAG_BODY,
	HTML_TAG_DIV,
	HTML_TAG_H1,
	HTML_TAG_H2,
	HTML_TAG_IMG,
	HTML_TAG_TABLE,
	HTML_TAG_TH,
	HTML_TAG_TR,
	HTML_TAG_TD,
	HTML_TAG_STYLE,
	HTML_TAG_P,

	HTML_TAG_COUNT
} HTML_TAG;

class htmlGen
{
	public:
		htmlGen( )
		{
			depth = 0;
		}

		void openTag( HTML_TAG tag, std::vector<std::string> properties = {}, bool newLineAfter = true );
		void closeTag( HTML_TAG tag, bool newLineAfter = true );
		void writeTagWithValue( HTML_TAG tag, std::string value, std::vector<std::string> properties = {}, bool autoClose = false, bool newLineAfter = true );
		void write( std::string value, bool newLineAfter = true, bool writeDepthBefore = true );

		void printData( );
		void writeFile( std::string fileName );
	private:
		std::ostringstream data;
		int depth;

		static const std::string tagList[ ];

		void writeTag( HTML_TAG tag, bool open, bool autoClose = false, std::vector<std::string> properties = {}, bool newLineAfter = true, bool writeDepthBefore = true );
		void writeDepth( );
};

#endif