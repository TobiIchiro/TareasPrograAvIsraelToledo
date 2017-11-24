/*
*EditorLineaxLinea.java Una clase para crear archivos de texto introduciendo 
*linea x linea (una linea a la vez)
*/

package Manejodeeventos;

import java.awt.Frame;
import java.awt.TextArea;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

/*
*@author yasser
*@version 2017.11.15
*/

public class EditosLineaxLinea implements ActionListener{
    Frame F;
    TextArea TA;
    Button B;
    TextField TF;
    Panel P;
    GridLayout GL;
    BorderLayout BL;
    
    public EditosLineaxLinea(){
        F = new Frame("Editor Linea por Linea");
        F.setLayout(BL=new BorderLayout());
        TA = new TextArea();
        F.add(TA, BorderLayout.CENTER);
        P=_hacerPanel();
        B.addActionListener(this);
        F.add(P,BorderLayout.SOUTH);
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent we){
                F.dispose();
                System.exit(0);
            }
        });
        TF.requestFocus();
        F.setVisible(true);
    }
    
    private Panel _hacerPanel(){
        Panel Presult = new Panel();
        Presult.setLayout(GL = new GridLayout(1,2));
        Presult.add(TF = new TextField(69));
        Presult.add(B = new Button("INGRESAR"));
        return Presult;
    }
    
    public void actionPerformed(ActionEvent ae){
        if(ae.getSource().equals(B)){
            String S = TA.getText(),s="";
            s = (S.equals(s))?s:"\n";
            S = S + s + TF.getText();
            TA.setText(S);
        }
    }
    
    public static void main(String[] args) {
        new EditosLineaxLinea();
    }
}