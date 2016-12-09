using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace DFS    // Algorithmus zur Tiefensuche (depth first search)
{
    public partial class Form1 : Form
    {
        private readonly double[,] am;   // Adjazenzmatrix des Graphen 
        private readonly int[] dfs_num;  // DFS-Numerierung (fortlaufende Numerierung besuchter Knoten)
        private readonly int[] bfs_num;  // BFS-Numerierung (fortlaufende Numerierung besuchter Knoten)

        private readonly int n;          // Anzahl Knoten
        private int number;              // Variable zum inkrementellen Hochzaehlen der Knoten

        public Form1()
        {
            InitializeComponent();

         // n = 6;                // Anzahl Knoten ist 6
            n = 19;

            // Instantiierung Matrizen und Vektoren
            am = new double[n, n];
            dfs_num = new int[n];
            bfs_num = new int[n];

            // Initialisierung der Adjazenzmatrix (Knoten 0 .. n-1)
            for (var i = 0; i < n; i++)
            {
                for (var j = 0; j < n; j++)
                {
                    am[i, j] = -1; // keine Verbindung zwischen Knonten i und j
                }
            }

            // Kanten eintragen (Beispieldaten)
            //am[0, 1] = 14;
            //am[0, 2] = 8;
            //am[1, 3] = 3;
            //am[1, 4] = 5;
            //am[2, 1] = 5;
            //am[2, 4] = 2;
            //am[3, 4] = 1;

            // alternativer Graph 
            am[0, 1] = 1;
            am[0, 2] = 1;
            am[1, 3] = 1;
            am[1, 4] = 1;
            am[3, 5] = 1;
            am[5, 6] = 1;
            am[5, 7] = 1;
            am[5, 8] = 1;
            am[8, 9] = 1;
            am[8, 10] = 1;
            am[10, 11] = 1;
            am[10, 12] = 1;
            am[13, 14] = 1;
            am[13, 15] = 1;
            am[14, 16] = 1;
            am[14, 17] = 1;
            am[16, 18] = 1;
            am[18, 8] = 1;
            am[11, 18] = 1;   // Zyklus eingebaut

            numericUpDown1.Minimum = 0;
            numericUpDown1.Maximum = n-1;
            numericUpDown2.Minimum = 0;
            numericUpDown2.Maximum = n-1;
        }

        // rekursive Tiefensuche
        void dfs(double [,] am, int v, int [] dfs_num, ref int number) 
        {    
            dfs_num[v] = ++number;                   // Knoten v besucht, Reihenfolgenummer incr.
            for(var i=0; i<n; i++)                   // Alle Knoten i durchlaufen, 
                if(am[v,i]>=0 && dfs_num[i]==0)      // die Nachfolger von v (Kante v->i) und nicht besucht
                    dfs(am, i, dfs_num, ref number); // Tiefensuche dfs ab neu erreichten Knoten i rekursiv
        }

        // iterative Tiefensuche
        void dfs_iter(double[,] am, int v, int[] dfs_num, ref int number) 
        {
            var s = new Stack<int>();               // neuen Stack s anlegen
            s.Push(v);                              // v als Element nach s
            while(s.Count > 0)                      // Solange s nicht leer
            {
                v = s.Pop();                        // v als oberstes Element von s entnehmen
                if(dfs_num[v] == 0)                 // wenn v nicht besucht
                {
                    dfs_num[v] = ++number;          // Knoten v besucht, Reihenfolgenummer incr.
                    for (var i = 0; i < n; i++)     // Alle Knoten i durchlaufen, 
                        if (am[v, i] >= 0)          // die Nachfolger i von v (Kante v->i)
                            s.Push(i);              // i als Element nach s
                }
            }
        }

        // Wegesuche mit rekursiver Tiefensuche
        void dfs_von_nach(double[,] am, int von, int nach, int[] dfs_num, ref bool found, Stack<int> s) 
        {
            dfs_num[von] = 1;                            // Knoten v besucht, Reihenfolgenummer incr.
            for (var i = 0; i < n; i++)                  // Alle Knoten i durchlaufen, 
                if (am[von, i] >= 0 && dfs_num[i] == 0)  // Nachfolger von von (Kante v->i) und nicht besucht
                {  
                    if (i == nach)                       // Ziel nach gefunden
                    {
                        // listBox1.Items.Add(String.Format("Weg nach {0} gefunden", i + 1));
                        s.Push(i);
                        dfs_num[nach] = 1;
                        found = true;                    // Weg gefunden
                        break;                           // for-Schleife verlassen
                    }
                    dfs_von_nach(am, i, nach, dfs_num, ref found,s); // rekursiver Aufruf

                    if (found)                           // Weg gefunden ?
                    {
                        // listBox1.Items.Add(String.Format("Knoten {0}", i + 1));
                        s.Push(i);                       // lokales i nach s
                        break;                           // for-Schleife verlassen
                    }  
                }
        }

        // iterative Breitensuche
        void bfs_iter(double[,] am, int v, int[] bfs_num, ref int number) 
        {
            var s = new Queue<int>();           // neue Queue s anlegen
            s.Enqueue(v);                       // v als Element nach s
            while (s.Count > 0)                 // Solange s nicht leer
            {
                v = s.Dequeue();                // v als erstes Element von s entnehmen
                if (bfs_num[v] != 0) continue;
               
                bfs_num[v] = ++number;          // Knoten v besucht, Reihenfolgenummer incr.
                for (var i = 0; i < n; i++)     // Alle Knoten i durchlaufen, 
                    if (am[v, i] >= 0)          // die Nachfolger i von v (Kante v->i)
                        s.Enqueue(i);           // i in Queue s einfuegen 
            }
        }

        // Zyklensuche
        void cycle(double [,] am, int v, int [] dfs_num, ref int number, out bool cyclus)
        {
            cyclus = false;
            dfs_num[v] = ++number;               // Knoten v besucht, Reihenfolgenummer incr.
            for (var i = 0; i < n; i++)          // Alle Knoten i durchlaufen
            {              
                if (cyclus) break;
                if (am[v, i] < 0) continue;      // Keine Kante v->i ? 
                                  
                if (dfs_num[i] == 0)             // Nachfolger i noch nicht besucht ?
                    cycle(am, i, dfs_num, ref number, out cyclus); // Zyklensuche cycle ab Knoten i
                else
                {
                    listBox1.Items.Add(String.Format("Zyklus von {0} nach {1}", v, i));
                    cyclus = true;               // Zyklus, Nachfolger i besucht
                }
            }
        }

        // Exit
        private void button2_Click(object sender, EventArgs e)  
        {
            Application.Exit();
        }

        // Start Tiefensuche DSF
        private void button1_Click(object sender, EventArgs e)  
        {
            for (var i = 0; i < n; i++)
                dfs_num[i] = 0;                      // Vektor besuchter Knoten initialisieren

            number = 0;                              // Zaehler initialisieren

            for (var i = 0; i < n; i++)              // Alle Knoten i (Kreuzungen) durchlaufen
            {
                if (dfs_num[i] == 0)                 // Knoten i noch nicht besucht ?
                    dfs(am, i, dfs_num, ref number); // Tiefensuche ab Knoten i
            }

            listBox1.Items.Add("Tiefensuche rekursiv");
            listBox1.Items.Add(String.Format("Knoten  Reihenfolge"));
            for (var i = 0; i < n; i++)
            {
                listBox1.Items.Add(String.Format("{0,6}       {1,6}", i, dfs_num[i]));
            }
        }

        // Start Zyklensuche
        private void button3_Click(object sender, EventArgs e) 
        {
            for (var i = 0; i < n; i++)
                dfs_num[i] = 0;                           // Vektor besuchter Knoten initialisieren

            number = 0;                                   // Zaehler initialisieren
            bool cyclus;

            for (var i = 0; i < n; i++)                   // Alle Knoten i (Kreuzungen) durchlaufen
            {
                if (dfs_num[i] == 0)                      // Knoten i noch nicht besucht ?
                {
                    cycle(am, i, dfs_num, ref number, out cyclus); // Zyklensuche ab Knoten i
                    if(cyclus) break;             // Zyklus gefunden, Abbruch beim 1.Zyklus
                }
            }
        }

        // Start listBox1 reinigen
        private void button4_Click(object sender, EventArgs e) 
        {
            listBox1.Items.Clear();
        }

        // Start Tiefensuche iterativ
        private void button5_Click(object sender, EventArgs e) 
        {
            for (var i = 0; i < n; i++)
                dfs_num[i] = 0;                           // Vektor besuchter Knoten initialisieren

            number = 0;                                   // Zaehler initialisieren

            for (var i = 0; i < n; i++)                   // Alle Knoten i (Kreuzungen) durchlaufen
            {
                if (dfs_num[i] == 0)                      // Knoten i noch nicht besucht ?
                    dfs_iter(am, i, dfs_num, ref number);      // iterative Tiefensuche ab Knoten i
            }

            listBox1.Items.Add("Tiefensuche iterativ");
            listBox1.Items.Add(String.Format("Knoten  Reihenfolge"));
            for (var i = 0; i < n; i++)
            {
                listBox1.Items.Add(String.Format("{0,6}       {1,6}", i, dfs_num[i]));
            }
        }

        // Start Breitensuche BSF iterativ
        private void button6_Click(object sender, EventArgs e) 
        {
            for (var i = 0; i < n; i++)
                bfs_num[i] = 0;                           // Vektor besuchter Knoten initialisieren

            number = 0;                                   // Zaehler initialisieren

            for (var i = 0; i < n; i++)                   // Alle Knoten i (Kreuzungen) durchlaufen
            {
                if (bfs_num[i] == 0)                      // Knoten i noch nicht besucht ?
                    bfs_iter(am, i, bfs_num, ref number);      // iterative Tiefensuche ab Knoten i
            }

            listBox1.Items.Add("Breitensuche iterativ");
            listBox1.Items.Add(String.Format("Knoten  Reihenfolge"));
            for (var i = 0; i < n; i++)
            {
                listBox1.Items.Add(String.Format("{0,6}       {1,6}", i, bfs_num[i]));
            }
        }

        // Start Weguche von -> nach
        private void button7_Click(object sender, EventArgs e) 
        {
            for (var i = 0; i < n; i++)
                dfs_num[i] = 0;                           // Vektor besuchter Knoten initialisieren

            var von = (int)numericUpDown1.Value;             // Knoten von
            var nach = (int)numericUpDown2.Value;            // Knoten nach
            var found = false;
            if (von == nach)
            {
                listBox1.Items.Add(String.Format("von und nach sollten unterschiedlich sein"));
                return;
            }

            var s = new Stack<int>();       // neuen Stack s anlegen
            
            dfs_von_nach(am, von, nach, dfs_num, ref found, s);    // Tiefensuche ab Knoten von
            if(found == false)
            {
                listBox1.Items.Add(String.Format("Kein Weg von {0} nach {1}", von, nach));
                return;
            }

            listBox1.Items.Add(String.Format("Weg von {0} nach {1}", von, nach));
            listBox1.Items.Add(String.Format(" Knoten"));
            s.Push(von);
            while(s.Count>0)
            {
                var i = s.Pop();
                listBox1.Items.Add(String.Format("{0,6}", i ));
            }
        }
    }
}
