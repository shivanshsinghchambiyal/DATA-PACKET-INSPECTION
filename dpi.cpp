#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class DPIEngine
{
private:

    unordered_set<string> blockedDomains;

    int totalPackets = 0;
    int totalBytes = 0;

    int tcpPackets = 0;
    int udpPackets = 0;

    int forwardedPackets = 0;
    int droppedPackets = 0;

    unordered_map<string, string> detectedApps;

public:

    void addBlockedDomain(string domain)
    {
        blockedDomains.insert(domain);
    }

    string detectApp(string domain)
    {
        if(domain.find("youtube") != string::npos)
            return "YouTube";

        if(domain.find("facebook") != string::npos)
            return "Facebook";

        if(domain.find("google") != string::npos)
            return "Google";

        if(domain.find("github") != string::npos)
            return "GitHub";

        return "Unknown";
    }

    bool isBlocked(string domain)
    {
        for(auto blocked : blockedDomains)
        {
            if(domain.find(blocked) != string::npos)
            {
                return true;
            }
        }

        return false;
    }

    void inspectPacket(string domain,
                       string protocol,
                       int bytes)
    {
        totalPackets++;

        totalBytes += bytes;

        if(protocol == "TCP" || protocol == "tcp")
        {
            tcpPackets++;
        }
        else
        {
            udpPackets++;
        }

        string app = detectApp(domain);

        detectedApps[domain] = app;

        if(isBlocked(domain))
        {
            droppedPackets++;
        }
        else
        {
            forwardedPackets++;
        }
    }

    void showDetectedDomains()
    {
        cout << "\n[Detected Domains/SNIs]\n";

        for(auto data : detectedApps)
        {
            cout << " - "
                 << data.first
                 << " -> "
                 << data.second
                 << endl;
        }
    }

    void showReport()
    {
        cout << "\n";
        cout << "====================================================\n";
        cout << "                 PROCESSING REPORT\n";
        cout << "====================================================\n\n";

        cout << "Total Packets:           "
             << totalPackets << endl;

        cout << "Total Bytes:             "
             << totalBytes << endl;

        cout << "TCP Packets:             "
             << tcpPackets << endl;

        cout << "UDP Packets:             "
             << udpPackets << endl;

        cout << "\nForwarded:               "
             << forwardedPackets << endl;

        cout << "Dropped:                 "
             << droppedPackets << endl;

        cout << "\n====================================================\n";
    }
};

int main()
{
    DPIEngine dpi;

    int rules;

    cout << "====================================================\n";
    cout << "          DPI ENGINE v2.0 (Multi-threaded)\n";
    cout << "====================================================\n\n";

    cout << "Load Balancers: 2    "
         << "FPs per LB: 2    "
         << "Total FPs: 4\n";

    cout << "\nEnter number of blocking rules: ";
    cin >> rules;

    cin.ignore();

    for(int i = 0; i < rules; i++)
    {
        string blockedDomain;

        cout << "Enter blocked app/domain "
             << i + 1
             << ": ";

        getline(cin, blockedDomain);

        dpi.addBlockedDomain(blockedDomain);

        cout << "[Rules] Blocked app: "
             << blockedDomain
             << endl;
    }

    int packets;

    cout << "\nEnter number of packets: ";
    cin >> packets;

    cin.ignore();

    cout << "\n[Reader] Processing packets...\n";

    for(int i = 0; i < packets; i++)
    {
        string domain;
        string protocol;

        int bytes;

        cout << "\nPacket "
             << i + 1
             << endl;

        cout << "Enter Domain/SNI: ";
        getline(cin, domain);

        cout << "Enter Protocol (TCP/UDP): ";
        getline(cin, protocol);

        cout << "Enter Packet Size (bytes): ";
        cin >> bytes;

        cin.ignore();

        dpi.inspectPacket(
            domain,
            protocol,
            bytes
        );
    }

    cout << "\n[Reader] Done reading "
         << packets
         << " packets\n";

    dpi.showDetectedDomains();

    dpi.showReport();

    return 0;
}