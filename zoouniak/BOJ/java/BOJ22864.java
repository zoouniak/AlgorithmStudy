package BOJ.java;

import java.util.*;
import java.lang.*;
import java.io.*;

public class BOJ22864
{
    public static void main (String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int a = Integer.parseInt(s[0]);//시간 당 피로도
        int b = Integer.parseInt(s[1]);//시간 당 일처리양
        int c = Integer.parseInt(s[2]);//시간 당 -피로도
        int m = Integer.parseInt(s[3]);//최대 피로도

        int nowTired=0;
        int work=0;
        for(int i=0;i<24;i++){
            if((nowTired+a)<=m){
                work+=b;
                nowTired+=a;
            }
            else{
                //쉬기
                nowTired=nowTired-c>0? nowTired-c:0;
            }
        }
        System.out.print(work);

    }
}