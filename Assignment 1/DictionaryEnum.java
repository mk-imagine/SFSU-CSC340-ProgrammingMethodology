/**
 *
 * @author Mark
 */
public enum DictionaryEnum {
    
    ARROW(
        "Arrow",
        new String[] {
            "noun"
        },
        new String[] {
            "Here is one arrow: <IMG> -=>> </IMG>"
        }
    ),
    DISTINCT(
        "Distinct",
        new String[] {
            "adjective",
            "adjective",
            "adverb",
            "noun",
            "noun",
            "noun",
            "noun",
            "noun"
        },
        new String[] {
            "Familiar. Worked in Java.",
            "Unique. No duplicates. Clearly different or of a different kind.",
            "Uniquely. Written \"distinctly\".",
            "A keyword in this assignment.",
            "A keyword in this assignment.",
            "A keyword in this assignment.",
            "An advanced search option.",
            "Distinct is a parameter in this assignment."
        }
    ),
    PLACEHOLDER(
        "Placeholder",
        new String[] {
            "adjective",
            "adjective",
            "adverb",
            "conjunction",
            "interjection",
            "noun",
            "noun",
            "noun",
            "preposition",
            "pronoun",
            "verb"
        },
        new String[] {
            "To be updated...",
            "To be updated...",
            "To be updated...",
            "To be updated...",
            "To be updated...",
            "To be updated...",
            "To be updated...",
            "To be updated...",
            "To be updated...",
            "To be updated...",
            "To be updated..."
        }
    ),
    CSC340(
        "CSC340",
        new String[] { 
            "adjective",
            "noun",
            "noun",
            "noun"
        },
        new String[] { 
            "= C++ version of CSC210 + CSC220 + more.",
            "A CS upper division course.",
            "Many hours outside of class.",
            "Programming Methodology."
        }
    ),
    CSC220(
        "CSC220",
        new String[] {
            "adjective",
            "verb",
        },
        new String[] {
            "Ready to create complex data structures.",
            "To create data structures.",
        }
    ),
    BOOK(
        "Book",
        new String[] {
            "noun",
            "noun",
            "verb",
            "verb"
        },
        new String[] {
            "A set of pages.",
            "A written work published in printed or electronic form.",
            "To arrange for someone to have a seat on a plane.",
            "To arrange something on a particular date."
        }
    ),
    ADVERB(
        "Adverb",
        new String[] {
            "noun"
        },
        new String[] {
            "Adverb is a word that adds more information about place, time, manner, cause or degree to a verb, an adjective, a phrase or another adverb."
        }
    ),
    ADJECTIVE(
        "Adjective", 
        new String[] {
            "noun"
        },
        new String[] {
            "Adjective is a word that describes a person or thing, for example big, red and clever in a big house, red wine and a clever idea."
        } 
    ),
    INTERJECTION(
        "Interjection", 
        new String[] {
            "noun"
        },
        new String[] {
            "Interjection is a short sound, word or phrase spoken suddenly to express an emotion. Oh!, Look out! and Ow! are interjections."
        }
    ),
    NOUN(
        "Noun", 
        new String[] {
            "noun"
        },
        new String[] {
            "Noun is a word that refers to a person, (such as Ann or doctor), a place (such as Paris or city) or a thing, a quality or an activity (such as plant, sorrow or tennis)."
        }
    );

    
    private final String KEYWORD;
    private final String[] PARTOFSPEECH;
    private final String[] DEFINITION;
    
    private DictionaryEnum(String KEYWORD, String[] PARTOFSPEECH, String[] DEFINITION) {
        this.KEYWORD = KEYWORD;
        this.PARTOFSPEECH = PARTOFSPEECH;
        this.DEFINITION = DEFINITION;
    }

    public String getKeyword() {
            return KEYWORD;
    }

    public String[] getPartOfSpeech() {
            return PARTOFSPEECH;
    }
    
    public String[] getDefinition() {
            return DEFINITION;
    }
}

