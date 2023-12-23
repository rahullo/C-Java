// public class reverseString {
//     public static void main(String[] args) {
//         String name = "BANARAS";


//         System.out.println(name.toCharArray());

//         int len=0;

//         for(char c: name.toCharArray()){
//             len++;
//         }



//         for(int i = len-1; i >-1; i--){
//             System.out.print(name.charAt(i));
//         }
        
//     }
// }

public class reverseString {
    public static void main(String[] args) {
        String str = "Hello, world!";
        char[] charArray = str.toCharArray();
        System.out.println(charArray);
        int start = 0;
        int end = charArray.length - 1;
        while (end > start) {
            char temp = charArray[start];
            charArray[start] = charArray[end];
            charArray[end] = temp;
            end--;
            start++;
        }
        String reversedString = new String(charArray);
        System.out.println("Original string: " + str);
        System.out.println("Reversed string: " + reversedString);
    }
}
