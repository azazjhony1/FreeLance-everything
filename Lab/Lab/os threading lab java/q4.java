public class q4 {
    public static void main(String[] args) {
        readthread r = new readthread();
        r.start();
        String s = r.readdata() ; 

        writethread w = new writethread();
        w.setdata(s);
        w.start();

    }
}
