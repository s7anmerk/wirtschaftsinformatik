using System;
using System.Windows.Forms;

namespace Floyd1
{
	/// <summary>
	/// Zusammendfassende Beschreibung für Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.ListBox listBox1;
		
		private double[,] am; // Adjazenzmatrix
		private int[,]    zm; // Matrix zum Auflösen der Zwischenknoten
		private int       n;  // Anzahl Knoten
		
		public Form1() {
			//
			// Erforderlich fuer die Windows Form-Designerunterstuetzung
			//
			InitializeComponent();

			//
			// TODO: Fügen Sie den Konstruktorcode nach dem Aufruf von InitializeComponent hinzu
			//
			n = 6; // Anzahl Knoten ist 6

			// Instantiierung Matrizen und Vektoren
			am = new double[n,n];
			zm = new int[n,n];

			// Initialisierung Matrizen und Vektoren
			for (var i=0; i<n; i++) {
				for (var j=0; j<n; j++) {
					if (i==j)
						am[i,j] = 0;  // Entfernung zu sich selbst ist 0
					else
						am[i,j] = -1; // sonst keine Verbindung
					zm[i,j] = -1;      // Verbindung ohne kein Zwischenknoten
				}
			}

			// Kanten eintragen (Beispieldaten)
			am[0,1] = 30;
			am[0,4] = 100;
			am[0,5] = 90;
			am[1,2] = 10;
			am[1,3] = 40;
			am[2,0] = 40;
			am[2,5] = 10;
			am[3,4] = 30;
			am[5,4] = 20;

			listBox1.Items.Add("Adjazenzmatrix fuer n = " + n.ToString() + " Knoten:");
			output();
		}

		/// <summary>
		/// Die verwendeten Ressourcen bereinigen.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
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
		private void InitializeComponent()
		{
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Gold;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(16, 873);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(120, 32);
            this.button1.TabIndex = 0;
            this.button1.Text = "Compute";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.LawnGreen;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.Location = new System.Drawing.Point(456, 873);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(120, 32);
            this.button2.TabIndex = 0;
            this.button2.Text = "End";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // listBox1
            // 
            this.listBox1.Font = new System.Drawing.Font("Courier New", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listBox1.ItemHeight = 15;
            this.listBox1.Location = new System.Drawing.Point(16, 8);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(560, 844);
            this.listBox1.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(600, 917);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// Der Haupteinstiegspunkt für die Anwendung.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}

		private void button1_Click(object sender, System.EventArgs e) {
			var timer = new Win32.HiPerfTimer();
			listBox1.Items.Add("");
			listBox1.Items.Add("Start des Algorithmus");

			timer.Start();
			floyd();
			timer.Stop();

			listBox1.Items.Add("Ende des Algorithmus");
			listBox1.Items.Add(String.Format("Rechenzeit {0:F2} [ms]", timer.Duration * 1000));
			listBox1.Items.Add("");
			listBox1.Items.Add("Entfernungen:");
			output();
            listBox1.Items.Add("");
            out_zm();
		}

		private void button2_Click(object sender, System.EventArgs e) {
			Application.Exit();
		}
		
		
		
		

		// Floyd Algorithmus iterativ abarbeiten
		private void floyd() {
		  for (var i=0; i<n; i++) 
		    for (var j=0; j<n; j++) 
		      for (var k=0; k<n; k++) 
			    // wenn Verbindugn j->i und i->k existiert
			    if (am[j,i] >= 0 && am[i,k] >= 0)
			      if ( am[j,k] < 0 ||                   // existiert noch gar nicht
				    (am[j,k] > am[j,i] + am[i,k]) ) { // oder Verbindung ist kürzer
				    am[j,k] = am[j,i] + am[i,k];      // Neue Kante j->k
				    zm[j,k] = i;	               // Verbindung j->k ueber Zwischenknoten i
				    listBox1.Items.Add(String.Format(
				       "neue Verbindung von Knoten {0} nach Knoten {1} ueber Knoten {2}",
				       j,k,i));
			       }
		}

		// Ausgabe der Ergebnisse
		private void output() {
		  for (var i=0; i<n; i++) 
		    for (var j=0; j<n; j++) 
		      if (i != j && am[i,j] >= 0) 
			if (zm[i,j] >= 0) 
				listBox1.Items.Add(String.Format(
				  "von Knoten {0} nach Knoten {1} Distance {2}\t( {0} {3})",
				  i,j,am[i,j],zknoten(i,j)));
			else
				listBox1.Items.Add(String.Format(
				   "von Knoten {0} nach Knoten {1} Distance {2}",
				   i,j,am[i,j]));
		}

		// Verbindung über Zwischenknoten
		private string zknoten(int i, int j) {
			if (zm[i,j] < 0)
				return (j).ToString() + " ";
			return zknoten(i,zm[i,j]) + zknoten(zm[i,j],j);
		}

        private void out_zm()
        {
            listBox1.Items.Add("Matrix zum Aufloesen der Zwischenknoten:");
            string s = "   nach | ";
            string u = "----------";
            for (int i = 0; i < n; i++)
            {
                s = s + String.Format("{0,5}", i);
                u = u + "-----";
            }
            listBox1.Items.Add(s);
            listBox1.Items.Add(u);

            for (int i = 0; i < n; i++)
            {
                s = String.Empty;
                for (int j = 0; j < n; j++)
                {
                    s = s + String.Format("{0,5}", (zm[i, j]>=0?zm[i, j]:-1));
                }
                if(i==0)
                    s = String.Format("von {0,3} | ", i) + s;
                else
                    s = String.Format("    {0,3} | ",i) + s;
                listBox1.Items.Add(s);
            }
        }
	}
}
