package com.task2;
import jdk.nashorn.internal.ir.CallNode;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.*;
import java.util.Scanner;
public class IO {
    private static Object File;

    public static void main(String[] args) throws IOException {
          System.out.println("parent:");
        Scanner sc = new Scanner(System.in);
        String  parent = sc.next();
        System.out.println("child:");
        String  child = sc.next();
        /*find the dir*/
      /*  File file1 = new File("F:","\\111");*/
        File file1 = new File(parent,child);
        System.out.println(file1);
        if(!file1.exists()){
            System.out.println("不存在该目录将新建：");
            file1.mkdirs();
        }
     /*   File file2 = new File("F:\\111\\111.txt");*/
        System.out.println("file:(pattern:double<\\>and<name>)");
        String f = sc.next();
        File file2 = new File(parent+child+f);
        if(!file2.exists()) {
            System.out.println("不存在该文件将新建：");
            file2.createNewFile();
        }
        System.out.println("now you found the dir\n");
        /*change the content int the file*/
      /*  OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream("F:\\111\\111.txt",true),"utf-8");*/
         OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(parent+child+f,true),"utf-8");
        FileReader fr = new FileReader(parent+child+f);
        int run=1;
       while(run==1) {
           getFile(fr);
           setFile(osw);
           System.out.println("entry 1 to continue change the file");
           run = sc.nextInt();
       }
        fr.close();
        osw.close();
        /* getAllFile(file1);*/
    }
        private    static void setFile(OutputStreamWriter osw) throws IOException {
            System.out.println("\nwhich line you wanna change?");
            Scanner sc = new Scanner(System.in);
            int line = sc.nextInt();
            for (int i = 1; i < line; i++) {
                osw.write("\t\n");
            }
            System.out.println("entry the content");
            String ct = sc.next();
            osw.write(ct);
            osw.flush();
        }

    private static  void  getFile(FileReader fr) throws IOException {
            int len;
            System.out.print("the file has :\n");
            while ((len = fr.read())!=-1){
                System.out.print((char)len);
            }

        }

    }


