#include <fstream>
#include <string>

#include "gtest/gtest.h"

#include "htmlGen.hpp"

using namespace std;

class HTMLGenTest : public ::testing::Test 
{
	protected:

		void SetUp( ) override
		{
		}

		void TearDown( ) override
		{

		}

		static void TestPrintedOutput( htmlGen& generator, string expected )
		{
			testing::internal::CaptureStdout( );

			generator.printData( );

			string output = testing::internal::GetCapturedStdout( );

			EXPECT_STREQ( expected.c_str( ), output.c_str( ) );
		}
};

TEST_F( HTMLGenTest, OpenCloseInvalidTag )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_COUNT );
	generator.closeTag( HTML_TAG_COUNT );

	TestPrintedOutput( generator, "" );
}

TEST_F( HTMLGenTest, OpenCloseTagHTML )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.closeTag( HTML_TAG_HTML );

	TestPrintedOutput( generator, "<html>\n</html>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagTitle )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_TITLE );
	generator.closeTag( HTML_TAG_TITLE );

	TestPrintedOutput( generator, "<title>\n</title>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagBody )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_BODY );

	TestPrintedOutput( generator, "<body>\n</body>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagDiv )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_DIV );
	generator.closeTag( HTML_TAG_DIV );

	TestPrintedOutput( generator, "<div>\n</div>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagH1 )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_H1 );
	generator.closeTag( HTML_TAG_H1 );

	TestPrintedOutput( generator, "<h1>\n</h1>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagH2 )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_H2 );
	generator.closeTag( HTML_TAG_H2 );

	TestPrintedOutput( generator, "<h2>\n</h2>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagImg )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_IMG );
	generator.closeTag( HTML_TAG_IMG );

	TestPrintedOutput( generator, "<img>\n</img>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagTable )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_TABLE );
	generator.closeTag( HTML_TAG_TABLE );

	TestPrintedOutput( generator, "<table>\n</table>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagTh )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_TH );
	generator.closeTag( HTML_TAG_TH );

	TestPrintedOutput( generator, "<th>\n</th>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagTr )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_TR );
	generator.closeTag( HTML_TAG_TR );

	TestPrintedOutput( generator, "<tr>\n</tr>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagTd )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_TD );
	generator.closeTag( HTML_TAG_TD );

	TestPrintedOutput( generator, "<td>\n</td>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagStyle )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_STYLE );
	generator.closeTag( HTML_TAG_STYLE );

	TestPrintedOutput( generator, "<style>\n</style>\n" );
}
TEST_F( HTMLGenTest, OpenCloseTagP )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_P );
	generator.closeTag( HTML_TAG_P );

	TestPrintedOutput( generator, "<p>\n</p>\n" );
}

TEST_F( HTMLGenTest, OpenCloseTagNested )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.openTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_HTML );

	TestPrintedOutput( generator, "<html>\n\t<body>\n\t</body>\n</html>\n" );
}

TEST_F( HTMLGenTest, OpenCloseTagWithProperties )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML, { "id=blah" } );
	generator.openTag( HTML_TAG_BODY, { "id=blah2", "test=one" } );
	generator.closeTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_HTML );

	TestPrintedOutput( generator, "<html id=blah>\n\t<body id=blah2 test=one>\n\t</body>\n</html>\n" );
}

TEST_F( HTMLGenTest, OpenCloseTagNoNewLines )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML, {}, false );
	generator.openTag( HTML_TAG_BODY, {}, false );
	generator.closeTag( HTML_TAG_BODY, false );
	generator.closeTag( HTML_TAG_HTML, false );

	TestPrintedOutput( generator, "<html>\t<body>\t</body></html>" );
}

TEST_F( HTMLGenTest, WriteTagWithValueSimple )
{
	htmlGen generator;

	generator.writeTagWithValue( HTML_TAG_P, "blahblah" );

	TestPrintedOutput( generator, "<p>blahblah</p>\n" );
}
TEST_F( HTMLGenTest, WriteTagWithValueProperties )
{
	htmlGen generator;

	generator.writeTagWithValue( HTML_TAG_P, "blahblah", { "id=one", "test=two" } );

	TestPrintedOutput( generator, "<p id=one test=two>blahblah</p>\n" );
}
TEST_F( HTMLGenTest, WriteTagWithValueAutoClose )
{
	htmlGen generator;

	generator.writeTagWithValue( HTML_TAG_P, "blahblah", {}, true );

	TestPrintedOutput( generator, "<p />\n" );
}
TEST_F( HTMLGenTest, WriteTagWithValueAutoCloseNoNewLine )
{
	htmlGen generator;

	generator.writeTagWithValue( HTML_TAG_P, "blahblah", {}, true, false );

	TestPrintedOutput( generator, "<p />" );
}

TEST_F( HTMLGenTest, WriteSimple )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.write( "blahblah" );
	generator.closeTag( HTML_TAG_HTML );

	TestPrintedOutput( generator, "<html>\n\tblahblah\n</html>\n" );
}
TEST_F( HTMLGenTest, WriteNoNewline )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.write( "blahblah", false );
	generator.closeTag( HTML_TAG_HTML );

	TestPrintedOutput( generator, "<html>\n\tblahblah</html>\n" );
}
TEST_F( HTMLGenTest, WriteNoDepth )
{
	htmlGen generator;

	generator.openTag( HTML_TAG_HTML );
	generator.write( "blahblah", true, false );
	generator.closeTag( HTML_TAG_HTML );

	TestPrintedOutput( generator, "<html>\nblahblah\n</html>\n" );
}

TEST_F( HTMLGenTest, WriteFile )
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