import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Substituition{
    static String sbs(String txt){
        Map letter_map = new HashMap<>();
        for (int i = 97; i <= 122; i++) {
            letter_map.put((char) i, (char) (122-i+97));
        }
        StringBuilder res = new StringBuilder();
        txt.chars().forEach(c->res.append(letter_map.getOrDefault((char)c, c)));
        return res.toString();
    }
   
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String txt = sc.nextLine();
        String enc = sbs(txt);
        String dec = sbs(enc);
        System.out.println(enc+"\n"+dec); 
        sc.close();
    }
}