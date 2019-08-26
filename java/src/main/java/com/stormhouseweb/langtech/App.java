package com.stormhouseweb.langtech;

import com.stormhouseweb.langtech.graphics.GraphicsLexer;
import com.stormhouseweb.langtech.graphics.GraphicsParser;
import org.antlr.v4.runtime.*;


/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) {
        String javaClassContent = "line from 0,0 to 0,10";
        GraphicsLexer lexer = new GraphicsLexer(CharStreams.fromString(javaClassContent));


        CommonTokenStream tokens = new CommonTokenStream(lexer);

        GraphicsParser parser = new GraphicsParser(tokens);

        parser.file();

    }
}
