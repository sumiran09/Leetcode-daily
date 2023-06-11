/*  ques: Snapshot Array
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length): initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val): sets the element at the given index to be equal to val.
int snap(): takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id): returns the value at the given index, at the time we took the snapshot with the given snap_id
 

Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5  */
 
class SnapshotArray {
public:
    int snapID;
    vector<vector<pair<int,int>>> historyrecord;
    SnapshotArray(int length) {
        snapID=0;
        historyrecord.resize(length);
        for(int i=0;i<length;i++){
            historyrecord[i].push_back(make_pair(0,0)); // format of [snap_id, value]. Initialize each list by adding the first record [0, 0]
        } 
    }
    
    void set(int index, int val) {  // add the historical record [snap_id, value] to the record list history_records[index]
        historyrecord[index].push_back(make_pair(snapID,val));
    }
    
    int snap() {
        return snapID++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(historyrecord[index].begin(), historyrecord[index].end(), make_pair(snap_id, INT_MAX)); //Use binary search to find the rightmost
      //insertion index of snapshot ID in the given version snap_index (so the target index is snap_idnex - 1).
        return prev(it)->second; // Return history_records[index][snap_index - 1][1]
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
