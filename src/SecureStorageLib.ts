import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  get: (key: string) => Promise<string | null>;
  set: (key: string, value: string) => Promise<void>;
  delete: (key: string) => Promise<void>;
  getAll: () => Promise<Record<string, string>>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('SecureStorage');
