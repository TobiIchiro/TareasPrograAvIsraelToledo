/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//Paso 1/5 ActionListener
package herenciayreutilizacion;
import java.awt.Dialog;
import java.awt.Frame;
import java.awt.MenuBar;
import java.awt.Menu;
import java.awt.MenuItem;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

/**
 *
 * @author Sala2
 */
public class Vprincipal {
    Frame F;
    MenuBar MB;
    Menu M;
    MenuItem MIAbrir;
    MenuItem MITipo;
    MyDialog MD;
    
    public Vprincipal(String str){
        F = new Frame("Ventana principal");
        F.setMenuBar(MB = new MenuBar());
        MB.add(M = new Menu("Archivo"));
        M.addSeparator();
        M.add(MIAbrir = new MenuItem("Abrir"));
        M.addSeparator();
        M.add(MITipo = new MenuItem("Tipo de votacion"));
        MITipo.addActionListener(new ListenMITipo());
        F.addWindowListener(new WindowAdapter(){
        public void windowClosing(WindowEvent we){
            F.dispose();
            System.exit(0);
        }
        });
        F.setSize(400,300);
        F.setVisible(true);
        
        
    
}
    class ListenMITipo implements ActionListener{//Paso 2/5 ActionListener
        public void actionPerformed(ActionEvent ae){
            MD = new MyDialog(F);//Paso 5/5
            
        }
    }
    public static void main(String arg[]){
            new Vprincipal("Ventana principal");
        }
    
}
