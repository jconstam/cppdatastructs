#include <fstream>

#include "gtest/gtest.h"

#include "htmlGen.hpp"

using namespace std;

TEST( HTMLGenTest, OpenCloseInvalidTag )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_COUNT );
	generator.closeTag( HTML_TAG_COUNT );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "", output.c_str( ) );
}

TEST( HTMLGenTest, OpenCloseTagBasic )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.openTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_HTML );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<html>\n\t<body>\n\t</body>\n</html>\n", output.c_str( ) );
}

TEST( HTMLGenTest, OpenCloseTagWithProperties )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML, { "id=blah" } );
	generator.openTag( HTML_TAG_BODY, { "id=blah2", "test=one" } );
	generator.closeTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_HTML );

	testing::internal::CaptureStdout( );
\
	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<html id=blah>\n\t<body id=blah2 test=one>\n\t</body>\n</html>\n", output.c_str( ) );
}

TEST( HTMLGenTest, OpenCloseTagNoNewLines )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML, {}, false );
	generator.openTag( HTML_TAG_BODY, {}, false );
	generator.closeTag( HTML_TAG_BODY, false );
	generator.closeTag( HTML_TAG_HTML, false );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<html>\t<body>\t</body></html>", output.c_str( ) );
}

TEST( HTMLGenTest, WriteTagWithValueSimple )
{
	htmlGen generator;

	generator.writeTagWithValue( HTML_TAG_P, "blahblah" );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<p>blahblah</p>\n", output.c_str( ) );
}
TEST( HTMLGenTest, WriteTagWithValueProperties )
{
	htmlGen generator;

	generator.writeTagWithValue( HTML_TAG_P, "blahblah", { "id=one", "test=two" } );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<p id=one test=two>blahblah</p>\n", output.c_str( ) );
}
TEST( HTMLGenTest, WriteTagWithValueAutoClose )
{
	htmlGen generator;

	generator.writeTagWithValue( HTML_TAG_P, "blahblah", {}, true );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<p />\n", output.c_str( ) );
}
TEST( HTMLGenTest, WriteTagWithValueAutoCloseNoNewLine )
{
	htmlGen generator;

	generator.writeTagWithValue( HTML_TAG_P, "blahblah", {}, true, false );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<p />", output.c_str( ) );
}

TEST( HTMLGenTest, WriteSimple )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.write( "blahblah" );
	generator.closeTag( HTML_TAG_HTML );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<html>\n\tblahblah\n</html>\n", output.c_str( ) );
}
TEST( HTMLGenTest, WriteNoNewline )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.write( "blahblah", false );
	generator.closeTag( HTML_TAG_HTML );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<html>\n\tblahblah</html>\n", output.c_str( ) );
}
TEST( HTMLGenTest, WriteNoDepth )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.write( "blahblah", true, false );
	generator.closeTag( HTML_TAG_HTML );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	EXPECT_STREQ( "<html>\nblahblah\n</html>\n", output.c_str( ) );
}

TEST( HTMLGenTest, WriteFile )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML, { "id=blah" } );
	generator.openTag( HTML_TAG_BODY, { "id=blah2", "test=one" } );
	generator.closeTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_HTML );

	testing::internal::CaptureStdout( );

	generator.printData( );

	string output = testing::internal::GetCapturedStdout( );

	generator.writeFile( "test.html" );

	struct stat buffer;
	ASSERT_EQ( 0, stat( "test.html", &( buffer ) ) );

	ifstream fileRead;
	fileRead.open( "test.html" );
	string fileContents( ( istreambuf_iterator<char>( fileRead ) ), istreambuf_iterator<char>( ) );

	EXPECT_STREQ( output.c_str( ), fileContents.c_str( ) );

	ASSERT_EQ( 0, remove( "test.html" ) );
}