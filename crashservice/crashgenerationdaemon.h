#pragma once
/*!
* ������Ϣ�ռ�������
*
*/
#include <QObject>
#include <QMap>
namespace google_breakpad{
	class CrashGenerationServer;
	class ClientInfo;
}
class CrashGenerationDaemon:public QObject
{
	Q_OBJECT
public:
	CrashGenerationDaemon(bool bService, QObject *parent = Q_NULLPTR);
	~CrashGenerationDaemon();

	bool CrashServerStart();
	void CrashServerStop();

	void cacheAppDumpFile(const QString& appName, const QString& dumpFile);

	void startCrashReporter(const ClientInfo* client_info);
private:
	bool									m_bService;						// �Ƿ��Ƿ���ģʽ	
	google_breakpad::CrashGenerationServer	*m_pCrashSvr;					// �����ռ�������
	QMap<QString, QString>					m_mapAppForDumpFile;			// Ӧ�ó����Ӧ��dump�ļ�
};
