/**
 * CSC340 Dictionary Assignment
 * @author Mark
 */

import com.google.common.collect.ArrayListMultimap;
import com.google.common.collect.Multimap;

import java.util.*;

public class Dictionary {
    
    private static final String[] ERROR = {
        "<Not found>",
        "<2nd argument must be part of speech or \'distinct\'>", 
        "<2nd argument must be part of speech or \'distinct\'>", // optional: and/or \'distinct\' and 3rd argument must be \'distinct\'>",
        "<Please enter only 3 arguments>"
    };
    private static final Multimap<String, String[]> DICT = ArrayListMultimap.create();
    private static final ArrayList<String> OUTPUT = new ArrayList<>();
    private static final ArrayList<String> PARTSOFSPEECH = new ArrayList<String>(
            Arrays.asList("adjective", "adverb", "noun", "conjunction", "interjection", "preposition", "pronoun", "verb"));
    private static String[] searchParams = new String[3];
    private static int errorNumber = -1;
    
    /**
     * initData Method
     * Initializes data from Dictionary340 enum database
     */
    public static void init() {
        System.out.println("! Loading data...");
        int numDots = 3;
        
        // iterate through enum database to populate internal data structure
        for (DictionaryEnum dict : DictionaryEnum.values()) {
            String keyWord = dict.getKeyword();
            String[] partOfSpeech = dict.getPartOfSpeech();
            String[] definition = dict.getDefinition();
            for (int i = 0; i < partOfSpeech.length; i++) {
                String[] keywordData = new String[2];
                keywordData[0] = partOfSpeech[i];
                keywordData[1] = definition[i];
                DICT.put(dict.getKeyword(), keywordData);
            }
        }
        System.out.println("! Loading completed...");
        System.out.println("\n" + "-----DICTIONARY 340 JAVA-----" + "\n");
    }
        
    /**
     * queryInput Method
     * Accepts user input to query internal data structures
     */
    private static void queryInput() {
        Scanner input = new Scanner(System.in);
        do {
            System.out.print("Search: ");
            String searchParam = input.nextLine();
            searchParams = searchParam.split("\\s");
            switch (searchParams.length) {
                case 1:
                    if (searchParams[0].equals("!Q")) {  // quit parameter
                        System.out.println("\n" + "-----Thank You!-----");
                        System.exit(0);
                    } else {
                        querryDictionary(searchParams[0], null, false);  // search for all instances
                        outputResults();
                    }
                    break;
                case 2:
                    if (PARTSOFSPEECH.contains(searchParams[1].toLowerCase())) { // search for word and use
                        querryDictionary(searchParams[0], searchParams[1], false);
                    } else if (searchParams[1].equalsIgnoreCase("distinct")) { // search for word and unique
                        querryDictionary(searchParams[0], null, true);
                    } else {
                        errorNumber = 1;  // 2nd argument incorrect
                    }
                    outputResults();
                    break;
                case 3:
                    if (PARTSOFSPEECH.contains(searchParams[1].toLowerCase())  // search for word, use, and unique
                            && searchParams[2].equalsIgnoreCase("distinct")) {
                        querryDictionary(searchParams[0], searchParams[1], true);
                    } else {
                        errorNumber = 2; // improper use of 2nd and 3rd argument
                    }
                    outputResults();
                    break;
                default:
                    errorNumber = 3; // too many arguments
                    outputResults();

            }
            errorNumber = -1; // reset errors
            OUTPUT.clear();
        } while (!searchParams[0].equals("!Q"));
    }
    
    /**
     * queryDict Method
     * @param keyword
     * @param partOfSpeech
     * @param distinct 
     * queries internal data structures and populates ArrayList with String output
     */
    public static ArrayList<String> querryDictionary(String keyword, String partOfSpeech, boolean distinct) {
        DICT.entries().forEach((entry) -> {
            String key = entry.getKey();
            String tempPartOfSpeech = entry.getValue()[0];
            String tempDefinition = entry.getValue()[1];
            
            // populates OUTPUT ArrayList only if terms match
            if (!key.equalsIgnoreCase(keyword)) {
            } else if (key.equalsIgnoreCase(keyword) && partOfSpeech == null) {
                OUTPUT.add(entry.getKey() + " [" + entry.getValue()[0] + "] : " + entry.getValue()[1]);
            } else if (key.equalsIgnoreCase(keyword) && tempPartOfSpeech.equalsIgnoreCase(partOfSpeech)) {
                OUTPUT.add(entry.getKey() + " [" + entry.getValue()[0] + "] : " + entry.getValue()[1]);
            }
        });
        if (distinct) {  // remove duplicates if looking for unique entries
            Set<String> distinctOutput = new TreeSet(OUTPUT);
            OUTPUT.clear();
            OUTPUT.addAll(distinctOutput);
        }
        if (OUTPUT.isEmpty()) {  // sets flag for none found
            errorNumber = 0;
        }
        return null;
    }
    
    /**
     * outputResults Method
     * Uses OUTPUT ArrayList to display results from query
     */
    private static void outputResults() {
        System.out.printf("%4s\n", "|");
        if (errorNumber >= 0) {  // prints flag if error or none found
            System.out.println("\t" + ERROR[errorNumber]);
        } else {
            OUTPUT.forEach((output) -> { // prints OUTPUT ArrayList
                System.out.println("\t" + output);
            });
        }
        System.out.printf("%4s\n", "|");
    }

    /**
     * main Method
     * @param args 
     */
    public static void main(String[] args){
        init();
        queryInput();
    }
}