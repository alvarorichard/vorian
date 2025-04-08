// Generated from /Users/krone/Documents/codes/vorian/PythonStyle.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class PythonStyleLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, ID=4, NUMBER=5, PLUS=6, MINUS=7, STAR=8, DIV=9, 
		DEF=10, IF=11, ELSE=12, RETURN=13, PRINT=14, COLON=15, NEWLINE=16, WS=17, 
		INDENT=18, DEDENT=19;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "ID", "NUMBER", "PLUS", "MINUS", "STAR", "DIV", 
			"DEF", "IF", "ELSE", "RETURN", "PRINT", "COLON", "NEWLINE", "WS", "INDENT", 
			"DEDENT"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "','", null, null, "'+'", "'-'", "'*'", "'/'", "'def'", 
			"'if'", "'else'", "'return'", "'print'", "':'", "'\\r?\\n'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, "ID", "NUMBER", "PLUS", "MINUS", "STAR", "DIV", 
			"DEF", "IF", "ELSE", "RETURN", "PRINT", "COLON", "NEWLINE", "WS", "INDENT", 
			"DEDENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	    // Aqui você pode adicionar códigos auxiliares, se necessário


	public PythonStyleLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "PythonStyle.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 18:
			DEDENT_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void DEDENT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			skip;
			break;
		}
	}

	public static final String _serializedATN =
		"\u0004\u0000\u0013q\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002"+
		"\u0012\u0007\u0012\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001"+
		"\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0005\u00030\b\u0003\n\u0003"+
		"\f\u00033\t\u0003\u0001\u0004\u0004\u00046\b\u0004\u000b\u0004\f\u0004"+
		"7\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007"+
		"\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001"+
		"\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\f"+
		"\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u0010\u0004\u0010b\b\u0010\u000b\u0010"+
		"\f\u0010c\u0001\u0010\u0001\u0010\u0001\u0011\u0004\u0011i\b\u0011\u000b"+
		"\u0011\f\u0011j\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0000\u0000\u0013\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004"+
		"\t\u0005\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017"+
		"\f\u0019\r\u001b\u000e\u001d\u000f\u001f\u0010!\u0011#\u0012%\u0013\u0001"+
		"\u0000\u0005\u0003\u0000AZ__az\u0004\u000009AZ__az\u0001\u000009\u0002"+
		"\u0000\t\t  \u0001\u0000\t\tt\u0000\u0001\u0001\u0000\u0000\u0000\u0000"+
		"\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000"+
		"\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b"+
		"\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001"+
		"\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001"+
		"\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001"+
		"\u0000\u0000\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001"+
		"\u0000\u0000\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001"+
		"\u0000\u0000\u0000\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000"+
		"\u0000\u0000%\u0001\u0000\u0000\u0000\u0001\'\u0001\u0000\u0000\u0000"+
		"\u0003)\u0001\u0000\u0000\u0000\u0005+\u0001\u0000\u0000\u0000\u0007-"+
		"\u0001\u0000\u0000\u0000\t5\u0001\u0000\u0000\u0000\u000b9\u0001\u0000"+
		"\u0000\u0000\r;\u0001\u0000\u0000\u0000\u000f=\u0001\u0000\u0000\u0000"+
		"\u0011?\u0001\u0000\u0000\u0000\u0013A\u0001\u0000\u0000\u0000\u0015E"+
		"\u0001\u0000\u0000\u0000\u0017H\u0001\u0000\u0000\u0000\u0019M\u0001\u0000"+
		"\u0000\u0000\u001bT\u0001\u0000\u0000\u0000\u001dZ\u0001\u0000\u0000\u0000"+
		"\u001f\\\u0001\u0000\u0000\u0000!a\u0001\u0000\u0000\u0000#h\u0001\u0000"+
		"\u0000\u0000%l\u0001\u0000\u0000\u0000\'(\u0005(\u0000\u0000(\u0002\u0001"+
		"\u0000\u0000\u0000)*\u0005)\u0000\u0000*\u0004\u0001\u0000\u0000\u0000"+
		"+,\u0005,\u0000\u0000,\u0006\u0001\u0000\u0000\u0000-1\u0007\u0000\u0000"+
		"\u0000.0\u0007\u0001\u0000\u0000/.\u0001\u0000\u0000\u000003\u0001\u0000"+
		"\u0000\u00001/\u0001\u0000\u0000\u000012\u0001\u0000\u0000\u00002\b\u0001"+
		"\u0000\u0000\u000031\u0001\u0000\u0000\u000046\u0007\u0002\u0000\u0000"+
		"54\u0001\u0000\u0000\u000067\u0001\u0000\u0000\u000075\u0001\u0000\u0000"+
		"\u000078\u0001\u0000\u0000\u00008\n\u0001\u0000\u0000\u00009:\u0005+\u0000"+
		"\u0000:\f\u0001\u0000\u0000\u0000;<\u0005-\u0000\u0000<\u000e\u0001\u0000"+
		"\u0000\u0000=>\u0005*\u0000\u0000>\u0010\u0001\u0000\u0000\u0000?@\u0005"+
		"/\u0000\u0000@\u0012\u0001\u0000\u0000\u0000AB\u0005d\u0000\u0000BC\u0005"+
		"e\u0000\u0000CD\u0005f\u0000\u0000D\u0014\u0001\u0000\u0000\u0000EF\u0005"+
		"i\u0000\u0000FG\u0005f\u0000\u0000G\u0016\u0001\u0000\u0000\u0000HI\u0005"+
		"e\u0000\u0000IJ\u0005l\u0000\u0000JK\u0005s\u0000\u0000KL\u0005e\u0000"+
		"\u0000L\u0018\u0001\u0000\u0000\u0000MN\u0005r\u0000\u0000NO\u0005e\u0000"+
		"\u0000OP\u0005t\u0000\u0000PQ\u0005u\u0000\u0000QR\u0005r\u0000\u0000"+
		"RS\u0005n\u0000\u0000S\u001a\u0001\u0000\u0000\u0000TU\u0005p\u0000\u0000"+
		"UV\u0005r\u0000\u0000VW\u0005i\u0000\u0000WX\u0005n\u0000\u0000XY\u0005"+
		"t\u0000\u0000Y\u001c\u0001\u0000\u0000\u0000Z[\u0005:\u0000\u0000[\u001e"+
		"\u0001\u0000\u0000\u0000\\]\u0005\r\u0000\u0000]^\u0005?\u0000\u0000^"+
		"_\u0005\n\u0000\u0000_ \u0001\u0000\u0000\u0000`b\u0007\u0003\u0000\u0000"+
		"a`\u0001\u0000\u0000\u0000bc\u0001\u0000\u0000\u0000ca\u0001\u0000\u0000"+
		"\u0000cd\u0001\u0000\u0000\u0000de\u0001\u0000\u0000\u0000ef\u0006\u0010"+
		"\u0000\u0000f\"\u0001\u0000\u0000\u0000gi\u0007\u0004\u0000\u0000hg\u0001"+
		"\u0000\u0000\u0000ij\u0001\u0000\u0000\u0000jh\u0001\u0000\u0000\u0000"+
		"jk\u0001\u0000\u0000\u0000k$\u0001\u0000\u0000\u0000lm\u0003\u001f\u000f"+
		"\u0000mn\u0006\u0012\u0001\u0000no\u0001\u0000\u0000\u0000op\u0006\u0012"+
		"\u0002\u0000p&\u0001\u0000\u0000\u0000\u0005\u000017cj\u0003\u0006\u0000"+
		"\u0000\u0001\u0012\u0000\u0000\u0001\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}