// Add songs.
int add_song(char *, char *);

// Search for a song.
struct song_node * search_song(char *, char*);

// Search for an artist.
struct song_node * search_artist(char *);

// Print out all the entries under a certain letter.
void print_letter(char letter);

// Print out all the songs of a certain artist
void print_artist(char* artist);

// Print out the entire library.
void print_lib();

// Shuffle - print out a series of randomly chosen songs.
void shuffle(int num_songs);

// Delete a song
void delete_song(char *, char *);

// Delete all the nodes.
void clear_lib();
