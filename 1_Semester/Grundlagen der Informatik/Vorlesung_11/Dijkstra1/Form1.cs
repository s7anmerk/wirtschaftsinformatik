using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace Dijkstra1 { // entspricht Prakt 16
	/// <summary>
	/// Zusammendfassende Beschreibung für Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form {
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;

		private double[,] am; // Adjazenzmatrix
		private double[,] wm; // Wegematrix, entspricht Adjazenzmatrix der kuerzesten Wege von s aus
		private double[]  d;  // Distanzvektor, entspricht akkumlierter Entfernung Knoten i zu Startknoten
		private bool[]    m;  // Markierungsvektor (true: unerkundeter Knoten; false: bereits erkundet)
		
		private int       n;  // Anzahl Knoten
		private int       s;  // Startknoten

		public Form1() {
			//
			// Erforderlich für die Windows Form-Designerunterstützung
			//
			InitializeComponent();

			//
			// TODO: Fuegen Sie den Konstruktorcode nach dem Aufruf von InitializeComponent hinzu
			//
			n = 6; // Anzahl Knoten ist 6
			s = 0; // Startknoten festlegen

            // Instantiierung Matrizen und Vektoren
            am = new double[n, n];
            wm = new double[n, n];
            d = new double[n];
            m = new bool[n];
		}

		/// <summary>
		/// Die verwendeten Ressourcen bereinigen.
		/// </summary>
		protected override void Dispose( bool disposing ) {
			if( disposing ) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung. 
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		private void InitializeComponent() {
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.Location = new System.Drawing.Point(24, 16);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox1.Size = new System.Drawing.Size(560, 590);
            this.textBox1.TabIndex = 2;
            this.textBox1.Text = "textBox1";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.LightGreen;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(36, 628);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(96, 24);
            this.button1.TabIndex = 0;
            this.button1.Text = "Start";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.OrangeRed;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.Location = new System.Drawing.Point(488, 628);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(96, 24);
            this.button2.TabIndex = 1;
            this.button2.Text = "Exit";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(608, 742);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button2);
            this.Name = "Form1";
            this.Text = "Algorithmus von Dijkstra in C#";
            this.ResumeLayout(false);
            this.PerformLayout();

		}
		#endregion

		/// <summary>
		/// Der Haupteinstiegspunkt für die Anwendung.
		/// </summary>
		[STAThread]
		static void Main() {
			Application.Run(new Form1());
		}

		private void button1_Click(object sender, System.EventArgs e) {
			Win32.HiPerfTimer timer = new Win32.HiPerfTimer();
            textBox1.Clear();

            // Initialisierung Matrizen und Vektoren
            for (int i = 0; i < n; i++)
            {
                m[i] = true;      // anfangs alle Knoten als unerkundet markieren
                d[i] = -1;        // Entfernung zum Startknoten ist unendlich -1
                for (int j = 0; j < n; j++)
                {
                    am[i, j] = -1; // keine Verbindung zwischen Knonten i und j
                    wm[i, j] = -1;
                }
            }

            // Kanten eintragen (Beispieldaten)
            am[0, 1] = 14;
            am[0, 2] = 8;
            am[1, 3] = 3;
            am[1, 4] = 5;
            am[2, 1] = 5;
            am[2, 4] = 2;
            am[3, 4] = 1;

            // Entfernung zum Startknoten ist 0
            d[s] = 0;

            textBox1.Text = "Dimension am [ " + am.GetLowerBound(0) + " : "
                + am.GetUpperBound(0) + " , "
                + am.GetLowerBound(1) + " : "
                + am.GetUpperBound(1) + " ]\r\n";

			timer.Start();
			dijkstra();
			timer.Stop();
			
			// Ausgabe der Ergebnisse
			textBox1.AppendText("\r\nEntfernungen:\r\n");
			for (int i=d.GetLowerBound(0); i<=d.GetUpperBound(0); i++)
				textBox1.AppendText(String.Format("d({0}) = {1}\r\n",i+1,d[i]));

			textBox1.AppendText("\r\nLösungsbaum:\r\n");
			for (int i=wm.GetLowerBound(0); i<=wm.GetUpperBound(0); i++)
				for (int j=wm.GetLowerBound(1); j<=wm.GetUpperBound(1); j++)
					if (wm[i,j] >= 0)
						textBox1.AppendText(String.Format("Kante von {0} nach {1} mit Länge = {2}\r\n",i+1,j+1,wm[i,j]));

			textBox1.AppendText("Ende des Algorithmus\r\n");
			textBox1.AppendText(String.Format("Rechenzeit {0:F8} [ms]\r\n", timer.Duration * 1000));
		}

		private void button2_Click(object sender, System.EventArgs e) {
			Application.Exit();
		}

		// Dijkstra Algorithmus iterativ abarbeiten
		private void dijkstra() {
		  while (knoten()) {                       // solange neuer erkundeter Knoten gefunden
			for (int i=0; i<n; i++) {              // alle Knoten "von"
				for (int j=0; j<n; j++) {          // alle Knoten "nach"
					if (i != j && am[i,j] >= 0 && m[i]==false && m[j]) { // Kante von i nach j ex. und i "erkundet" und j "unerkundet" ?
						// für j existiert noch keine Entfernung zum Startknoten
						if (d[j] < 0) {            // j neuer "Grenzknoten"
							d[j] = d[i] + am[i,j]; // Distanz nach j ueber i
						}
						else {
						     // nach j existiert kürzerer Weg über i
							if (d[j] > (d[i] + am[i,j]))  // neuer Weg nach j ueber i kuerzer als bisherige Distanz nach j ?
								d[j] = (d[i] + am[i,j]);  // Aktualisierung der Distanz nach j ueber i
							// bisherige Grenzkanten zuruecksetzen
							for (int k=0; k<n; k++) 
								if (wm[k,j] >= 0) wm[k,j] = -1;  // Verbindung von k nach j zuruecksetzen
						}
						// Grenzkante setzen
						wm[i,j] = am[i,j];      // Kante von i nach j gehoert zum kuerzesten Weg nach j
						textBox1.AppendText(String.Format("Distanz({0}) = {1}\r\n",
						       j+1, d[j]));
					}
				}
			}			
		  }
		}

		// existiert noch wählbarer Knoten?
		private bool knoten() {
			int min = -1;                          // Anfangswert vor for-Schleife
			for (int i=0; i<n; i++) {
				if (m[i] && d[i] >= 0)             // Knoten i unerkundet und Distanz nach i >= 0 ?
					if (min < 0 || d[i] < d[min])  // erstmaliger Aufruf for-Schleife oder Distanz zu i < Distanz vorheriger Knoten min
						min = i;                   // min = i  (>=0) ist Knotenindex mit d[min] ist minimaler Abstand
			}
			if (min >= 0) {                        // wurde Knoten mit minimaler Distanz gefunden ?
				m[min] = false;                    // Knoten mit Index min gilt als "erkundet"
				textBox1.AppendText(String.Format("Knoten {0} erkundet\r\n", min+1));
				return true;                       // neuer erkundeter Knoten gefunden
			}
			return false;                          // kein erkundeter Knoten gefunden
		}
	}
}
