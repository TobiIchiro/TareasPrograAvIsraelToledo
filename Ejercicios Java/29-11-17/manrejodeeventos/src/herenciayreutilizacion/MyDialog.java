/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package herenciayreutilizacion;
import java.awt.Dialog;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
*@author Julio Morales, Israel Toledo, Yasser Manriquez
*/
public class MyDialog implements ActionListener{
    Dialog D;
    Checkbox CB1,CB2,CB3,CB4,CB5,CB6;
    Button BC, BA;
    Label S;
    
    //public MyDialog(String puesto[]){
    public MyDialog(Frame f){
        //D = new Dialog(new Frame(),"Tipo de eleccion");
        D = new Dialog(f,"Tipo de eleccion");
        D.setLayout(new GridBagLayout());
        GridBagConstraints c=new GridBagConstraints();
        CB1 = new Checkbox("Presidente de la república");
        CB2 = new Checkbox("Senador");
        CB3 = new Checkbox("Diputado");
        CB4 = new Checkbox("Gobernador");
        CB5 = new Checkbox("Delegado");
        CB6 = new Checkbox("Presidente municipal");
        S= new Label("  ");
        c.gridx=0;
        D.add(S, c);
        c.weighty = 1;
        c.weightx = 1;
        c.gridx = 1;
        c.anchor = GridBagConstraints.WEST;
        c.insets = new Insets(0,0,0,0);
        D.add(CB1,c); 
        D.add(CB2,c);
        D.add(CB3,c);
        D.add(CB4,c);
        D.add(CB5,c);
        D.add(CB6,c);
        BC=new Button("Cancelar");
        c.weighty = 1;
        c.weightx = 1;
        c.gridx = 3;
        c.gridy = 4;
        c.ipadx = 50;
        c.anchor = GridBagConstraints.LAST_LINE_START;
        c.insets = new Insets(0,0, 0, 0);
        D.add(BC,c);
        BA = new Button("Aceptar");
        c.weighty = 1;
        c.weightx=1;
        c.gridx=3;
        c.gridy=1;
        c.anchor = GridBagConstraints.LAST_LINE_START;
        c.insets = new Insets(0,0, 0, 0);
        D.add(BA,c);
        //GridBagLayout
        D.setSize(400,300);
        D.setVisible(true);
        D.setLocationRelativeTo(null);
        
        D.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent we){
                D.dispose();
                System.exit(0);
                } 
            });
        BA.addActionListener(this);
        BC.addActionListener(this);
    }
    
public void actionPerformed(ActionEvent ae){
    if(ae.getSource().equals(BC)){
        System.out.println("Boton cancelar");
    }
    if(ae.getSource().equals(BA)){
        System.out.println("Boton aceptar");;
    }
}
public static void main(String[] args) {}
        //new MyDialog(args);
        
        
}

