/***********************************************************************
 * buecher_func.c
 * Sammlung von Funktionen zur Bücherlisten-Verwaltung
 *
 * Autor: H. Radners (Rumpfprogramm)
 ***********************************************************************/

#include "buecher_func.h"

/***********************************************************************/

void buecher_read(FILE *infile,
                  Buch buecher[], int *num_buch, const int MAXBUCH,
                  Autor autoren[], int *num_autor, const int MAXAUTOR,
                  Verlag verlage[], int *num_verlag, const int MAXVERLAG) {
   /* Liest das komplette Eingabe-file zeilenweise von (bereits
    * geöffnetem) infile ein */

   enum { MAXLL = 240 };   /* max. input line length */
   char c, linebuf[MAXLL]; /* Einlesepuffer für eine Zeile */

   fgets(linebuf, sizeof(linebuf), infile); /* 1x Kopfzeile ueberlesen */

   /* Schleife ueber alle Bücher-Datensätze, speichern */
   while (fgets(linebuf, sizeof(linebuf), infile)) {

      if (*num_buch >= MAXBUCH) {    /* Feldgroesse absichern */
         fprintf(stderr,
                 " *** Hinweis: Mehr als %d Bücher auf der Datei!\n", MAXBUCH);
         break;
      }

      /* Zeilenlänge absichern */
      if (linebuf[strlen(linebuf) - 1] != '\n') {   /* Zeile zu lang! */
         fprintf(stderr,
                 " *** Hinweis: Zeile auf der Datei zu lang (>%d)! ", MAXLL);
         fprintf(stderr, "Diese Zeile ignoriert:\n *** >%s...<\n", linebuf);
         while ((c = fgetc(infile)) != EOF) { /* Rest der überlangen Zeile ... */
            if (c == '\n') break;             /* ... überlesen bis NL od. EOF  */
         }
         continue;   /* diesen (unvollständigen) Buch-Datensatz ignorieren */
      }

      /* dieses Buch mit Verweisen auf Autor und Verlag speichern */
      buch_add(linebuf, buecher, num_buch,
               autoren, num_autor, MAXAUTOR,
               verlage, num_verlag, MAXVERLAG);
   }

}

/***********************************************************************/

void buch_add(char linebuf[],
              Buch buecher[], int *num_buch,
              Autor autoren[], int *num_autor, const int MAXAUTOR,
              Verlag verlage[], int *num_verlag, const int MAXVERLAG) {
   /* Erhält die eingelesene Eingabezeile eines Buch-Datensatzes,
    * zerlegt diese am Trennzeichen in die Attribute und speichert diese.
    * In der Buch-Struktur werden Zeiger auf dessen Autor- und Verlag-
    * Element gespeichert.
    */

   const char *delim = ";\n";    /* CSV-Trennzeichen + NL! */

   /* Zeile zerlegen und Teile speichern */
   /* Titel;Autor;Verlag;Erscheinungsjahr;ISBN */
   buecher[*num_buch].titel            = strdup(strtok(linebuf, delim));
   buecher[*num_buch].autor            = NULL;  /* TODO */
   buecher[*num_buch].verlag           = NULL;  /* TODO */
   buecher[*num_buch].erscheinungsjahr = 0;     /* TODO */
   buecher[*num_buch].isbn             = NULL;  /* TODO */

   /* Autor im bisherigen Autoren-Feld suchen, ggfs. neu anlegen,
    * pointer darauf im akt. Buch speichern */
   /* TODO */

   /* Verlag im bisherigen Verlage-Feld suchen, ggfs. neu anlegen,
    * pointer darauf im akt. Buch speichern */
   /* TODO */

   (*num_buch)++;

}

/***********************************************************************/

void buecher_print(Buch buecher[], const int num_buch) {
   /* Iteriert über Bücherliste zur Ausgabe */

   unsigned int i;

   for (i = 0; i < num_buch; i++) {
      printf("%3d: ", i + 1);
      buch_print(&(buecher[i]));
   }
   printf("\n");
}

/***********************************************************************/

void buch_print(const Buch *b) {
   /* Gibt ausgewählte Attribute eines Buches formatiert aus */

   printf("%s (%d): %s\n",
          (b->autor != NULL ? b->autor->name : "*unbekannt*"),
          b->erscheinungsjahr, b->titel);
}

/***********************************************************************/

