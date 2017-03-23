/* 
 * 
 */
#include "qtservice.h"
#include <QApplication>


class CrashGenerationDaemon;
class CrashServiceApp :public QtService<QCoreApplication>
{
public:
	CrashServiceApp(int argc, char **argv);
	virtual ~CrashServiceApp();
protected:
	virtual void start() override;
	virtual void stop() override;
private:
	bool							m_bService;								// �Ƿ��Ƿ���ģʽ	
	CrashGenerationDaemon			*m_pCrashGenSvr;						// �����ռ�������
};