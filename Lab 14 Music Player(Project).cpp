#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

class Song {
private:
    string title;
    string artist;
    int duration;
public:
    Song(string t = "", string a = "", int d = 0) : title(t), artist(a), duration(d) {}

    string getTitle() const {
	 return title; 
	}
	 
    string getArtist() const { 
	return artist;
	}
	 
    int getDuration() const { 
	return duration;
	}

    bool operator<(const Song& other) const {
	return title < other.title; 
	}
	 
    bool operator==(const Song& other) const { 
	return title == other.title; 
	}
};

class RecentSongs {
private:
    struct Node {
        Song song;
        Node* next;
        Node(const Song& s, Node* n = nullptr) : song(s), next(n) {}
    };
    
    Node* top;
    int size;
    const int max_size = 5;

public:
    RecentSongs() : top(nullptr), size(0) {}
    
    ~RecentSongs() {
        while(top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const Song& song) {
        if(size >= max_size) {
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }
        top = new Node(song, top);
        size++;
    }

    void display() const {
        Node* temp = top;
        cout << "Recently Played Songs:\n";
        while(temp) {
            cout << "-> " << temp->song.getTitle() << endl;
            temp = temp->next;
        }
    }
};

class PlayNextQueue {
private:
    struct Node {
        Song song;
        Node* next;
        Node(const Song& s, Node* n = nullptr) : song(s), next(n) {}
    };
    Node* front;
    Node* rear;

public:
    PlayNextQueue() : front(nullptr), rear(nullptr) {}
    
    ~PlayNextQueue() {
        while(front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(const Song& song) {
        Node* newNode = new Node(song);
        if(rear) {
            rear->next = newNode;
            rear = newNode;
        } else {
            front = rear = newNode;
        }
        cout << "Added to queue: " << song.getTitle() << endl;
    }

    Song dequeue() {
        if(!front) throw runtime_error("Queue is empty");
        Song data = front->song;
        Node* temp = front;
        front = front->next;
        if(!front) rear = nullptr;
        delete temp;
        return data;
    }

    bool isEmpty() const { 
	return front == nullptr; 
	}

    void display() const {
        Node* temp = front;
        cout << "Play Next Queue:\n";
        while(temp) {
            cout << "-> " << temp->song.getTitle() << endl;
            temp = temp->next;
        }
    }
};

class SongCatalog {
private:
    struct TreeNode {
        Song song;
        TreeNode* left;
        TreeNode* right;
        TreeNode(const Song& s) : song(s), left(nullptr), right(nullptr) {}
    };
    TreeNode* root;

    TreeNode* insert(TreeNode* node, const Song& song) {
        if(!node) 
		return new TreeNode(song);
        if(song.getTitle() < node->song.getTitle())
            node->left = insert(node->left, song);
        else
            node->right = insert(node->right, song);
        return node;
    }

    bool search(TreeNode* node, const string& title) const {
        if(!node) 
		return false;
        if(node->song.getTitle() == title) 
		return true;
        if(title < node->song.getTitle())
            return search(node->left, title);
        return search(node->right, title);
    }

public:
    SongCatalog() : root(nullptr) {}
    
    void addSong(const Song& song) {
        root = insert(root, song);
    }

    bool searchSong(const string& title) const {
        return search(root, title);
    }
};

class Playlist {
private:
    struct Node {
        Song song;
        Node* prev;
        Node* next;
        Node(const Song& s, Node* p = nullptr, Node* n = nullptr) 
            : song(s), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    Node* current;
    int size;

    Node* merge(Node* a, Node* b) {
        if(!a) return b;
        if(!b) return a;

        if(a->song < b->song) {
            a->next = merge(a->next, b);
            if(a->next) a->next->prev = a;
            a->prev = nullptr;
            return a;
        } else {
            b->next = merge(a, b->next);
            if(b->next) b->next->prev = b;
            b->prev = nullptr;
            return b;
        }
    }

    Node* mergeSort(Node* head) {
        if(!head || !head->next) 
		return head;
        
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* mid = slow->next;
        slow->next = nullptr;
        if(mid) mid->prev = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);

        return merge(left, right);
    }

    Node* findMin(Node* start) {
        Node* minNode = start;
        Node* current = start;
        while(current) {
            if(current->song < minNode->song)
                minNode = current;
            current = current->next;
        }
        return minNode;
    }

public:
    Playlist() : head(nullptr), tail(nullptr), current(nullptr), size(0) {}
    
    ~Playlist() {
        Node* temp = head;
        while(temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void addSong(const Song& song) {
        Node* newNode = new Node(song, tail, nullptr);
        if(tail) tail->next = newNode;
        else head = newNode;
        tail = newNode;
        size++;
        if(!current) current = head;
    }

    bool removeSong(const string& title) {
        Node* temp = head;
        while(temp) {
            if(temp->song.getTitle() == title) {
                if(temp->prev) temp->prev->next = temp->next;
                else head = temp->next;

                if(temp->next) temp->next->prev = temp->prev;
                else tail = temp->prev;

                if(current == temp) current = temp->next ? temp->next : temp->prev;
                
                delete temp;
                size--;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    Song getCurrentSong() const {
        if(!current) throw runtime_error("Playlist is empty");
        return current->song;
    }

    void moveNext() {
        if(current && current->next) current = current->next;
    }

    void movePrev() {
        if(current && current->prev) current = current->prev;
    }

    void moveToRandom() {
        if(size == 0) return;
        int index = rand() % size;
        Node* temp = head;
        for(int i = 0; i < index; ++i) temp = temp->next;
        current = temp;
    }

    void display() const {
        Node* temp = head;
        while(temp) {
            cout << temp->song.getTitle() << " - " << temp->song.getArtist()
                 << " (" << temp->song.getDuration() << "s)\n";
            temp = temp->next;
        }
    }

    bool isEmpty() const { 
		return size == 0; 
		}

    void sort() {
        head = mergeSort(head);
        Node* temp = head;
        tail = nullptr;
        while(temp && temp->next) {
            temp->next->prev = temp;
            temp = temp->next;
        }
        tail = temp;
        current = head;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        Node* temp = head;
        while(temp) {
            file << temp->song.getTitle() << ","
                 << temp->song.getArtist() << ","
                 << temp->song.getDuration() << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void loadFromFile(const string& filename) {
        Node* temp = head;
        while(temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = current = nullptr;
        size = 0;

        ifstream file(filename);
        if(!file.is_open()) return;

        string line;
        while(getline(file, line)) {
            size_t comma1 = line.find(',');
            size_t comma2 = line.find(',', comma1+1);
            if(comma1 == string::npos || comma2 == string::npos) 
			continue;

            string title = line.substr(0, comma1);
            string artist = line.substr(comma1+1, comma2-comma1-1);
            int duration = stoi(line.substr(comma2+1));
            addSong(Song(title, artist, duration));
        }
        file.close();
    }
};

class MusicPlayer {
private:
    Playlist playlist;
    RecentSongs recentSongs;
    PlayNextQueue playNext;
    SongCatalog catalog;
    int volume;
    bool isPlaying;
    bool isPaused;
    bool shuffleMode;
    const string filename = "playlist.txt";

public:
    MusicPlayer() : volume(50), isPlaying(false), isPaused(false), shuffleMode(false) {
        playlist.loadFromFile(filename);
    }

    ~MusicPlayer() {
        playlist.saveToFile(filename);
    }

    void play() {
        if(playlist.isEmpty()) {
            cout << "Playlist is empty!\n";
            return;
        }
        try {
            Song current = playlist.getCurrentSong();
            recentSongs.push(current);
            if(isPaused) {
                isPaused = false;
                isPlaying = true;
                cout << "Resumed: " << current.getTitle() << endl;
            } 
			else 
			{
                isPlaying = true;
                cout << "Now playing: " << current.getTitle() << endl;
            }
        } catch(const exception& e) {
            cout << e.what() << endl;
        }
    }

    void pause() {
        if(isPlaying) {
            isPaused = true;
            isPlaying = false;
            cout << "Paused playback\n";
        }
    }

    void stop() {
        isPlaying = false;
        isPaused = false;
        cout << "Playback stopped\n";
    }

    void nextSong() {
        if(playNext.isEmpty()) {
            if(shuffleMode) playlist.moveToRandom();
            else playlist.moveNext();
        } 
		else 
		{
            Song queued = playNext.dequeue();
            playlist.addSong(queued);
            playlist.moveNext();
        }
        
        if(isPlaying || isPaused) {
            cout << "Switched to: " << playlist.getCurrentSong().getTitle() << endl;
        }
    }

    void previousSong() {
        playlist.movePrev();
        if(isPlaying || isPaused) {
            cout << "Switched to: " << playlist.getCurrentSong().getTitle() << endl;
        }
    }

    void adjustVolume(int vol) {
        volume = max(0, min(100, vol));
        cout << "Volume set to " << volume << endl;
    }

    void toggleShuffle() {
        shuffleMode = !shuffleMode;
        cout << "Shuffle " << (shuffleMode ? "ON" : "OFF") << endl;
    }

    void addSong(const Song& song) {
        playlist.addSong(song);
        catalog.addSong(song);
        cout << "Added: " << song.getTitle() << endl;
    }

    void removeSong(const string& title) {
        if(playlist.removeSong(title)) {
            cout << "Removed: " << title << endl;
        } 
		else 
		{
            cout << "Song not found!\n";
        }
    }

    void showPlaylist() const {
        cout << "\nCurrent Playlist (" << (shuffleMode ? "Shuffle ON" : "Shuffle OFF") << "):\n";
        playlist.display();
        cout << endl;
    }

    void showRecentSongs() {
        recentSongs.display();
    }

    void sortPlaylist() {
        playlist.sort();
        cout << "Playlist sorted alphabetically!\n";
    }

    void searchCatalog(const string& title) {
        if(catalog.searchSong(title)) {
            cout << "Song found in catalog!\n";
        } 
		else {
		}
    }

    void addToQueue(const Song& song) {
        playNext.enqueue(song);
    }

    void showQueue() {
        playNext.display();
    }
};

void displayMenu() {
	cout<<"---------------------------------------------------------";
    cout << "\n********  Music Player Menu  ********\n";
    cout<<"---------------------------------------------------------\n";	
    cout << "1. Add Song\n";
    cout << "2. Remove Song\n";
    cout << "3. Show Playlist\n";
    cout << "4. Play\n";
    cout << "5. Pause\n";
    cout << "6. Stop\n";
    cout << "7. Next Song\n";
    cout << "8. Previous Song\n";
    cout << "9. Adjust Volume\n";
    cout << "10. Toggle Shuffle\n";
    cout << "11. Show Recent Songs\n";
    cout << "12. Sort Playlist\n";
    cout << "13. Search Catalog\n";
    cout << "14. Add to Queue\n";
    cout << "15. Show Queue\n";
    cout << "16. Exit\n";
    cout<<"\n";
    cout << "Enter your choice: ";
}

int main() {
    srand(time(0));
    MusicPlayer player;
    int choice;
    string title, artist;
    int duration, volume;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: 
			{
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter duration (seconds): ";
                cin >> duration;
                cin.ignore();
                player.addSong(Song(title, artist, duration));
                break;
            }
            case 2: 
			{
                cout << "Enter song title to remove: ";
                getline(cin, title);
                player.removeSong(title);
                break;
            }
            case 3:
                player.showPlaylist();
                break;
            case 4:
                player.play();
                break;
            case 5:
                player.pause();
                break;
            case 6:
                player.stop();
                break;
            case 7:
                player.nextSong();
                break;
            case 8:
                player.previousSong();
                break;
            case 9: 
			{
                cout << "Enter volume (0-100): ";
                cin >> volume;
                player.adjustVolume(volume);
                break;
            }
            case 10:
                player.toggleShuffle();
                break;
            case 11:
                player.showRecentSongs();
                break;
            case 12:
                player.sortPlaylist();
                break;
            case 13: 
			{
                cout << "Enter song title to search: ";
                getline(cin, title);
                player.searchCatalog(title);
                break;
            }
            case 14: 
			{
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter duration (seconds): ";
                cin >> duration;
                cin.ignore();
                player.addToQueue(Song(title, artist, duration));
                break;
            }
            case 15:
                player.showQueue();
                break;
            case 16:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } 
	while(choice != 16);

    return 0;
}